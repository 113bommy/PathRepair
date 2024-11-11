#include <bits/stdc++.h>
using namespace std;
int n, m, k, A[100100], B[100100], C[100100], x;
bool vis[100100];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> A[i] >> B[i] >> C[i];
  int ans = 2000000000;
  for (int i = 0; i < k; i++) {
    cin >> x;
    vis[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (vis[A[i]] != vis[B[i]]) ans = min(ans, C[i]);
  }
  if (ans == 2000000000)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
