#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int r[N], s[N], x[N];
vector<int> v[N];
pair<int, int> ans[500005];
pair<int, int> seg[4 * N];
pair<int, int> update(int l, int u, int i, int a, int b) {
  if (l >= a && u <= a) return seg[i] = {b, a};
  if (l > a || u < a) return seg[i];
  return seg[i] = max(update(l, ((l + u) / 2), (i * 2 + 1), a, b),
                      update(((l + u) / 2) + 1, u, (i * 2 + 2), a, b));
}
pair<int, int> query(int l, int u, int i, int a, int b) {
  if (l >= a && u <= b) return seg[i];
  if (l > a || u < a) return {0, -1};
  return max(query(l, ((l + u) / 2), (i * 2 + 1), a, b),
             query(((l + u) / 2) + 1, u, (i * 2 + 2), a, b));
}
int findr(int k) {
  if (k == r[k]) return k;
  return findr(r[k]);
}
void UNION(int a, int b) {
  int r1 = findr(a), r2 = findr(b);
  if (r1 == r2) return;
  if (s[r1] < s[r2]) swap(r1, r2);
  r[r2] = r1;
  s[r1] += s[r2];
  for (int j : v[r2]) v[r1].push_back(j);
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    r[i] = i;
    s[i] = 1;
    v[i].push_back(i);
  }
  pair<int, int> e[m + 1];
  set<int> ss;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    e[i] = {a, b};
    ss.insert(i);
  }
  pair<int, int> qq[q + 5];
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    qq[i] = {a, b};
    if (a == 1) continue;
    ss.erase(b);
  }
  for (int j : ss) {
    UNION(e[j].first, e[j].second);
  }
  for (int i = q; i >= 1; i--) {
    if (qq[i].first == 2) {
      UNION(e[qq[i].second].first, e[qq[i].second].second);
    } else {
      int temp = findr(qq[i].second);
      ans[i] = {v[temp][0], v[temp].size() - 1};
    }
  }
  int loc[n + 1];
  for (int i = 1; i <= n; i++) loc[i] = -1;
  int b = 0;
  for (int i = 1; i <= n; i++) {
    if (loc[i] != -1) continue;
    int k = findr(i);
    for (int j : v[k]) {
      update(0, n - 1, 0, b, x[j]);
      loc[j] = b++;
    }
  }
  for (int i = 1; i <= q; i++) {
    if (qq[i].first == 2) continue;
    pair<int, int> homie = query(0, n - 1, 0, loc[ans[i].first],
                                 loc[ans[i].first] + ans[i].second);
    cout << homie.first << endl;
    update(0, n - 1, 0, homie.second, 0);
  }
}
