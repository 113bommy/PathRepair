#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, n, m;
  cin >> n;
  if (n == 1) {
    cout << "-1";
    return 0;
  } else if (n == 2) {
    cout << 2 << " " << 3 << " " << 6;
    return 0;
  } else if (n % 2 == 0) {
    n /= 2;
    long long int p1 = n + 2;
    long long int p2 = p1 * (n + 1);
    long long int p3 = n * (n + 1);
    if (p1 <= 1e9 && p2 <= 1e9 && p3 <= 1e9) {
      cout << p1 << " " << p2 << " " << p3;
      return 0;
    }
    cout << -1;
    return 0;
  } else {
    long long int p = (n - 1) / 2;
    long long int f1 = p + 1;
    long long int f2 = (p + 1) * n;
    long long int a1 = f1 + 1;
    long long int a2 = (f1 * (a1));
    if (a1 != f2 && a2 != f2 && a1 <= 1e9 && a2 <= 1e9 && f2 <= 1e9 &&
        a1 != a2) {
      cout << a1 << " " << a2 << " " << f2;
      return 0;
    }
    a1 = f2 + 1;
    a2 = (f2 * (a1));
    {
      if (a1 != f1 && a2 != f1 && a1 <= 1e9 && a2 <= 1e9 && f1 <= 1e9 &&
          a1 != a2) {
        cout << a1 << " " << a2 << " " << f1;
        return 0;
      }
    }
    cout << "-1";
    return 0;
  }
}
