#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  while (tt--) {
    long long int n;
    cin >> n;
    long long int a[n], i;
    for (i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
      cout << "1 1\n0\n1 1\n0\n1 1\n" << (-a[0]) << "\n";
    } else {
      cout << "1 1\n" << (-a[0]) << "\n1 " << n << "\n0 ";
      for (i = 1; i < n; i++) cout << (-a[i]) * n << " ";
      cout << "\n2 " << n << "\n";
      for (i = 0; i < n; i++) cout << (n - 1) * a[i] << " ";
    }
  }
}
