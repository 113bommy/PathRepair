#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> b(n - 1);
    vector<long long int> c(n - 2);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    for (long long int i = 0; i < n - 1; i++) cin >> b[i];
    for (long long int i = 0; i < n - 1; i++) cin >> c[i];
    int x, y, ans1, ans2;
    x = (a[0] ^ b[0]);
    for (long long int i = 1; i < n - 1; i++) x = (x ^ a[i] ^ b[i]);
    ans1 = (x ^ a[n - 1]);
    y = (b[0] ^ c[0]);
    for (long long int i = 1; i < n - 2; i++) y = (y ^ a[i] ^ b[i]);
    ans2 = (y ^ a[n - 2]);
    cout << ans1 << "\n" << ans2;
  }
  return 0;
}
