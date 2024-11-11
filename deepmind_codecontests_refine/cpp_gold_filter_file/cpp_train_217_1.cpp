#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int R[N], I[N], S[N];
int Find(int u) {
  if (R[u] == u) return u;
  R[u] = Find(R[u]);
  return R[u];
}
void Union(int u, int v) {
  int ru = Find(u), rv = Find(v);
  if (ru == rv) return;
  if (I[ru] < R[rv]) swap(ru, rv);
  R[rv] = ru;
  I[ru] += I[rv];
  S[ru] += S[rv];
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    R[i] = i;
    I[i] = 1;
    S[i] = 0;
  }
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    S[a] = 1;
  }
  vector<vector<int>> E(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    cin >> E[i][1] >> E[i][2] >> E[i][0];
  }
  sort(E.begin(), E.end());
  int result;
  for (int i = 0; i < m; i++) {
    Union(E[i][1], E[i][2]);
    int r = Find(E[i][1]);
    if (S[r] == k) {
      result = E[i][0];
      break;
    }
  }
  while (k--) cout << result << ' ';
  cout << endl;
  return 0;
}
