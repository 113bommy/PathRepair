#include <bits/stdc++.h>
using namespace std;
void aeh() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
}
int32_t main() {
  aeh();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int p = n % 2, z = k % 2;
    if (p == 1 && z == 0)
      cout << "NO" << endl;
    else if (p == 1 || (p == 0 && z == 0)) {
      if (k - 1 > n)
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        for (long long int i = 0; i < k - 1; i++) cout << "1 ";
        cout << n - k + 1 << endl;
      }
    } else {
      if ((k - 1) * 2 > n)
        cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        for (long long int i = 0; i < k - 1; i++) cout << "2 ";
        cout << n - 2 * k + 2 << endl;
      }
    }
  }
}
