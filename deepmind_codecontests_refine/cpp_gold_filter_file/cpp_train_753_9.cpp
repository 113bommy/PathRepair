#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    k = k % 2 + 2;
    while (k--) {
      long long int ma = 0;
      for (int i = 0; i < n; i++) ma = max(ma, a[i]);
      for (int i = 0; i < n; i++) a[i] = ma - a[i];
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
  }
  return 0;
}
