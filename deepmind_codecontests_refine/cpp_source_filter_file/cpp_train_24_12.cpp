#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, temp = 0;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    if (a[0] + a[1] <= a[n - 1]) {
      cout << 1 << " " << 2 << " " << n - 1 << "\n";
      temp = 1;
    }
    if (temp == 0) cout << -1 << "\n";
  }
}
