#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 * 1000 + 100;
struct person {
  int res, age, num, start, end, gs;
  vector<pair<int, int> > v;
} p[maxn];
struct qq {
  int F, S, num;
} w[maxn];
int t[maxn], mmax[maxn * 3], sum[maxn * 3], g[maxn], nb[maxn];
int n, q, k, c;
bool cmd1(person i, person j) { return (i.age < j.age); }
bool cmd2(person i, person j) { return (i.res < j.res); }
bool cmd3(qq i, qq j) {
  return (max(p[i.F].res, p[i.S].res) > max(p[j.F].res, p[j.S].res));
}
void update1(int x, int l, int r, int xx) {
  if (xx > r || xx < l) return;
  if (xx == l && xx == r) {
    sum[x]++;
    return;
  }
  int mid = (l + r) / 2;
  sum[x]++;
  update1(2 * x, l, mid, xx);
  update1(2 * x + 1, mid + 1, r, xx);
}
int query1(int x, int l, int r, int xx, int yy) {
  if (xx > r || yy < l)
    return 0;
  else if (l >= xx && r <= yy)
    return sum[x];
  int mid = (l + r) / 2;
  return query1(2 * x, l, mid, xx, yy) + query1(2 * x + 1, mid + 1, r, xx, yy);
}
void update2(int x, int l, int r, int xx, int yy) {
  if (xx > r || xx < l) return;
  if (xx == l && xx == r) {
    mmax[x] = max(mmax[x], yy);
    return;
  }
  int mid = (l + r) / 2;
  mmax[x] = max(mmax[x], yy);
  update2(2 * x, l, mid, xx, yy);
  update2(2 * x + 1, mid + 1, r, xx, yy);
}
int query2(int x, int l, int r, int xx, int yy) {
  if (xx > r || yy < l)
    return 0;
  else if (l >= xx && r <= yy)
    return mmax[x];
  int mid = (l + r) / 2;
  return max(query2(2 * x, l, mid, xx, yy),
             query2(2 * x + 1, mid + 1, r, xx, yy));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i].res;
  for (int i = 0; i < n; i++) cin >> p[i].age;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> w[i].F >> w[i].S;
    w[i].num = i;
    w[i].F--;
    w[i].S--;
    p[w[i].F].v.push_back(make_pair(i, 0));
    p[w[i].S].v.push_back(make_pair(i, 1));
  }
  sort(p, p + n, cmd1);
  for (int i = 0; i < n; i++) {
    t[i] = p[i].age;
    p[i].num = i;
    for (int j = 0; j < p[i].v.size(); j++) {
      if (p[i].v[j].second == 0)
        w[p[i].v[j].first].F = i;
      else
        w[p[i].v[j].first].S = i;
    }
  }
  for (int i = 0; i < q; i++)
    if (w[i].F > w[i].S) swap(w[i].F, w[i].S);
  for (int i = 0; i < n; i++) {
    p[i].start = lower_bound(t, t + n, t[i] - k) - t;
    p[i].end = upper_bound(t, t + n, t[i] + k) - t - 1;
  }
  sort(w, w + q, cmd3);
  sort(p, p + n, cmd2);
  for (int i = 0; i < n; i++) {
    update1(1, 0, n - 1, p[i].num);
    p[i].gs = query1(1, 0, n - 1, p[i].start, p[i].end);
  }
  c = n - 1;
  for (int i = 0; i < n; i++) g[p[i].num] = i;
  for (int i = 0; i < q; i++) {
    while (p[c].res >= max(p[g[w[i].F]].res, p[g[w[i].S]].res) && c >= 0) {
      update2(1, 0, n - 1, p[c].num, p[c].gs);
      c--;
    }
    int d = -1;
    if (p[g[w[i].S]].start <= p[g[w[i].F]].end)
      d = query2(1, 0, n - 1, p[g[w[i].S]].start, p[g[w[i].F]].end);
    if (d <= 0)
      nb[w[i].num] = -1;
    else
      nb[w[i].num] = d;
  }
  for (int i = 0; i < q; i++) cout << nb[i] << "\n";
  return 0;
}
