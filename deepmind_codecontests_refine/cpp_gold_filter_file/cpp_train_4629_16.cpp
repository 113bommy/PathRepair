#include <bits/stdc++.h>
using namespace std;
void kehsihba() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int32_t main() {
  kehsihba();
  long long n;
  cin >> n;
  if (n <= 3) {
    cout << "NO";
  } else {
    cout << "YES" << '\n';
    if (n % 2 == 0) {
      cout << "1 * 2 = 2" << '\n';
      cout << "3 * 2 = 6" << '\n';
      cout << "4 * 6 = 24" << '\n';
      for (long long i = 5; i <= n; i += 2) {
        cout << i + 1 << " - " << i << " = " << 1 << '\n';
        cout << "24 * 1 = 24" << '\n';
      }
    } else {
      cout << "1 + 4 = 5" << '\n';
      cout << "5 * 5 = 25" << '\n';
      cout << "3 - 2 = 1" << '\n';
      cout << "25 - 1 = 24" << '\n';
      for (long long i = 6; i <= n; i += 2) {
        cout << i + 1 << " - " << i << " = " << 1 << '\n';
        cout << "24 * 1 = 24" << '\n';
      }
    }
  }
}
