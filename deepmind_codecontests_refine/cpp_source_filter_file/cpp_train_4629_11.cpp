#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  if (n < 4)
    cout << "NO";
  else {
    cout << "YES\n";
    if (n % 2 == 0) {
      cout << "1 *2 = 2\n";
      cout << "3 * 4 = 12\n";
      cout << "12 * 2 =24\n";
      for (int i = 5; i <= n; i += 2) {
        cout << i + 1 << " - " << i << " = "
             << "1\n";
        cout << "24 * 1 = 24\n";
      }
    } else {
      cout << "5 * 4 = 20\n";
      cout << "3 - 1 = 2\n";
      cout << "2 * 2 = 4\n";
      cout << "20 + 4= 24\n";
      for (int i = 6; i <= n; i += 2) {
        cout << i + 1 << " - " << i << " = "
             << "1\n";
        cout << "24 * 1 = 24\n";
      }
    }
  }
}
