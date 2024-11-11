#include <bits/stdc++.h>
using namespace std;
int n, t, tot;
struct node {
  int s, r, id;
};
node a[200005], st[200005];
map<pair<int, int>, int> mp;
vector<int> save[200005];
bool cmp(node x, node y) {
  if (x.s == y.s) return x.r < y.r;
  return x.s > y.s;
}
void add(int i) {
  node tmp = a[i];
  while (t > 1) {
    int r1 = st[t - 2].r, r2 = st[t - 1].r, r3 = tmp.r;
    int s1 = st[t - 2].s, s2 = st[t - 1].s, s3 = tmp.s;
    if (1LL * (r1 * r2 - r2 * r3) * (s2 * s3 - s1 * s3) >
        1LL * (r1 * r3 - r2 * r3) * (s2 * s3 - s1 * s2))
      t--;
    else
      break;
  }
  st[t++] = tmp;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int s, r;
    scanf("%d%d", &s, &r);
    if (mp.find(pair<int, int>(s, r)) == mp.end()) {
      tot++;
      mp[pair<int, int>(s, r)] = tot;
      a[tot].s = s;
      a[tot].r = r;
      a[tot].id = tot;
      save[tot].push_back(i);
    } else
      save[mp[pair<int, int>(s, r)]].push_back(i);
  }
  n = tot;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) add(i);
  int l = -1, r = -1, val = -1000000000;
  for (int i = 0; i < t; i++) {
    if (st[i].s >= val) {
      val = st[i].s;
      l = i;
    }
  }
  val = -1000000000;
  for (int i = 0; i < t; i++) {
    if (st[i].r > val) {
      val = st[i].r;
      r = i;
    }
  }
  if (l > r) swap(l, r);
  vector<int> ans;
  for (int j = l; j <= r; j++)
    for (auto x : save[st[j].id]) ans.push_back(x);
  sort(ans.begin(), ans.end());
  for (auto x : ans) printf("%d ", x);
  return 0;
}
