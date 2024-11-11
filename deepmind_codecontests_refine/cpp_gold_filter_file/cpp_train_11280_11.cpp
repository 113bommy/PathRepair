#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k != 1) {
    if (n > m + 1) {
      cout << 2 * k << endl;
      for (long long int i = 0; i < k; i++) {
        cout << 1 << " ";
      }
      for (long long int i = 0; i < k; i++) {
        cout << m + 2 << " ";
      }
      cout << endl;
    } else if (n == m + 1) {
      cout << 2 * k << endl;
      for (long long int i = 0; i < k; i++) {
        cout << 1 << " ";
      }
      cout << n << " ";
      for (long long int i = 0; i < k - 1; i++) {
        cout << m + 2 << " ";
      }
    } else {
      cout << 2 * k + 1 << endl;
      for (long long int i = 0; i < k; i++) {
        cout << 1 << " ";
      }
      cout << n << " ";
      for (long long int i = 0; i < k - 1; i++) {
        cout << n + 1 << " ";
      }
      cout << n + m << endl;
    }
  } else {
    if (n > m + 1) {
      cout << 2 << endl;
      cout << 1 << " " << m + 2 << " " << endl;
    } else if (n == m + 1) {
      cout << 3 << endl;
      cout << 1 << " " << n << " " << n + m << endl;
    } else {
      if (n >= 3) {
        cout << 3 << endl;
        cout << 1 << " " << n << " " << n + m - 1 << endl;
      } else {
        cout << 4 << endl;
        cout << 1 << " " << 2 << " " << 3 << " " << 4 << endl;
      }
    }
  }
  return 0;
}
