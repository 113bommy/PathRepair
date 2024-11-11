#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  if (n <= 3) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  if (n == 4) {
    cout << "1 + 2 = 3\n";
    cout << "3 + 3 = 6\n";
    cout << "6 * 4 = 24\n";
    return 0;
  }
  if (n == 5) {
    cout << "3 + 5 = 8\n";
    cout << "8 + 4 = 12\n";
    cout << "12 * 2 = 24\n";
    cout << "24 * 1 = 24\n";
    return 0;
  }
  if (n % 2 == 0) {
    cout << "1 + 2 = 3\n";
    cout << "3 + 3 = 6\n";
    cout << "6 * 4 = 24\n";
    for (long long int i = 6; i <= n; i += 2) {
      cout << i << " - " << i - 1 << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  } else {
    cout << "3 + 5 = 8\n";
    cout << "8 + 4 = 12\n";
    cout << "12 * 2 = 24\n";
    cout << "24 * 1 = 24\n";
    for (long long int i = 7; i <= n; i += 2) {
      cout << i << " - " << i - 1 << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  }
  return 0;
}
