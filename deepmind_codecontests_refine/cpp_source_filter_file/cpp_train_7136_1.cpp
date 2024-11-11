#include <bits/stdc++.h>
using namespace std;
const int mN = 1e3 + 10, mQ = 1e5 + 100;
int t[mQ], a[mQ], b[mQ], ans[mQ], arr[mN][mN], tot, bk[mQ], rows[mN];
bool xr[mN];
vector<int> Qi[mQ];
vector<int> adj[mQ];
int n, m, q;
bool mark(int idx) {
  if (!idx) return 0;
  if (t[idx] == 1) {
    if (xr[a[idx]] ^ arr[a[idx]][b[idx]] == 0) {
      rows[a[idx]]++;
      arr[a[idx]][b[idx]] ^= 1;
      tot++;
      return 1;
    }
  } else if (t[idx] == 2) {
    if (xr[a[idx]] ^ arr[a[idx]][b[idx]] == 1) {
      rows[a[idx]]--;
      arr[a[idx]][b[idx]] ^= 1;
      tot--;
      return 1;
    }
  } else if (t[idx] == 3) {
    xr[a[idx]] ^= 1;
    tot += m - 2 * rows[a[idx]];
    rows[a[idx]] = m - rows[a[idx]];
    return 1;
  }
  return 0;
}
void unmark(int idx) {
  if (t[idx] == 1) {
    arr[a[idx]][b[idx]] ^= 1;
    rows[a[idx]]--;
    tot++;
  } else if (t[idx] == 2) {
    arr[a[idx]][b[idx]] ^= 1;
    rows[a[idx]]++;
    tot--;
  } else {
    xr[a[idx]] ^= 1;
    tot += m - 2 * rows[a[idx]];
    rows[a[idx]] = m - rows[a[idx]];
  }
}
void bt(int idx) {
  if (t[idx] == 4) return;
  bool c = mark(idx);
  for (int i = 0; i < Qi[idx].size(); ++i) ans[Qi[idx][i]] = tot;
  for (int i = 0; i < adj[idx].size(); ++i) bt(adj[idx][i]);
  if (c) unmark(idx);
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i <= q; i++) bk[i] = i;
  adj[0].push_back(1);
  for (int z = 1; z <= q; z++) {
    scanf("%d", &t[z]), scanf("%d", &a[z]);
    if (t[z] <= 2) scanf("%d", &b[z]);
    if (t[z] == 4) {
      bk[z] = bk[a[z]];
      adj[bk[z]].push_back(z + 1);
      Qi[bk[z]].push_back(z);
    } else {
      Qi[z].push_back(z), adj[z].push_back(z + 1);
    }
  }
  bt(0);
  for (int i = 0; i < q; ++i) printf("%d\n", ans[i + 1]);
};
