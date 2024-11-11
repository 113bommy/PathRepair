#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 10, N = 20, mod = 1e9 + 7;
vector<int> adj[mxN];
pair<int, int> l[mxN];
int power[mxN], basis[N + 1], sz = 0, ar[mxN], ans[mxN];
void insertVector(int mask) {
  for (int i = 0; i < N; i++) {
    if ((mask & 1 << i) == 0) continue;
    if (!basis[i]) {
      basis[i] = mask;
      sz++;
      return;
    }
    mask ^= basis[i];
  }
}
bool checkXor(int mask) {
  for (int i = 0; i <= N; i++) {
    if ((mask & 1 << i) == 0) continue;
    if (!basis[i]) return false;
    mask ^= basis[i];
  }
  return true;
}
int main() {
  int n, m, i, j, a, b;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> ar[i];
  for (i = 1; i <= m; i++)
    cin >> l[i].first >> l[i].second, adj[l[i].first].push_back(i);
  power[0] = 1;
  for (i = 1; i < mxN; i++) power[i] = (power[i - 1] * 2LL) % mod;
  for (i = 1; i <= n; i++) {
    insertVector(ar[i]);
    for (auto cur : adj[i])
      if (checkXor(l[cur].second)) ans[cur] = power[i - sz];
  }
  for (i = 1; i <= m; i++) cout << ans[i] << endl;
  return 0;
}
