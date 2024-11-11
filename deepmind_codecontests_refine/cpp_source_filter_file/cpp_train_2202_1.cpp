#include <bits/stdc++.h>
using namespace std;
int n;
bool op[300003];
struct node {
  int ind;
  int max1;
  int cnt;
  node() {
    max1 = 0;
    cnt = 0;
  }
  node(int _ind) {
    ind = _ind;
    max1 = 0;
    cnt = 0;
  }
};
node d[300003];
vector<int> v[300003];
void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> op[i];
  for (int i = 1; i < n; ++i) {
    int par;
    cin >> par;
    v[par - 1].push_back(i);
  }
}
void dfs_sz(int tmp) {
  if (v[tmp].empty()) {
    d[tmp].max1 = 1;
    d[tmp].cnt = 1;
    return;
  }
  if (op[tmp]) d[tmp].max1 = -300003;
  for (int i = 0; i < v[tmp].size(); ++i) {
    int nb = v[tmp][i];
    dfs_sz(nb);
    d[tmp].cnt += d[nb].cnt;
    if (op[tmp])
      d[tmp].max1 = max(d[tmp].max1, d[nb].max1 - d[nb].cnt);
    else
      d[tmp].max1 += (d[nb].cnt - 1);
  }
  if (op[tmp])
    d[tmp].max1 += d[tmp].cnt;
  else
    ++d[tmp].max1;
}
void solve() {
  dfs_sz(0);
  cout << d[0].max1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  input();
  solve();
  return 0;
}
