#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
vector<pair<int, int> > q[maxN];
vector<int> d[maxN];
int pos[maxN], a[maxN], res[maxN], n, m;
int data[4 * maxN];
void add(int p, int x, int s = 0, int e = n, int id = 1) {
  data[id] += x;
  if (e - s < 2) return;
  int mid = (s + e) >> 1;
  if (p < mid)
    add(p, x, s, mid, 2 * id);
  else
    add(p, x, mid, e, 2 * id + 1);
}
int get(int l, int r, int s = 0, int e = n, int id = 1) {
  if (e <= l || r <= s) return 0;
  if (l <= s && e <= r) return data[id];
  int mid = (s + e) >> 1;
  return get(l, r, s, mid, 2 * id) + get(l, r, mid, e, 2 * id + 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      if (pos[i] < pos[j])
        d[j].push_back(i);
      else
        d[i].push_back(j);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    q[r].push_back(make_pair(i, l));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d[a[i]].size(); j++) {
      int cur = d[a[i]][j];
      int p = pos[cur];
      add(p, 1);
    }
    for (int j = 0; j < q[i].size(); j++) {
      int idx = q[i][j].first;
      int l = q[i][j].second;
      int r = i;
      res[idx] = get(l, r + 1);
    }
  }
  for (int i = 0; i < m; i++) cout << res[i] << endl;
  return 0;
}
