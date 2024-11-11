#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int adj[n][n];
  int a, b;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    ans += min(arr[a], arr[b]);
  }
  cout << ans << endl;
  return 0;
}
