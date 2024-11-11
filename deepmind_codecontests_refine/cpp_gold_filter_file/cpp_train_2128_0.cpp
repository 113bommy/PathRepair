#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 1 && k == 0) {
    cout << "1\n";
    return 0;
  }
  if (n / 2 > k) {
    cout << "-1" << '\n';
    return 0;
  }
  if (n == 1 && k > 1) {
    cout << "-1\n";
    return 0;
  }
  if (n == 1 && k == 1) {
    cout << "-1\n";
    return 0;
  }
  int a = 0, b = 0;
  if (n > 1) {
    if (n / 2 != k) {
      a = k - n / 2 + 1;
      b = 2 * a;
    } else {
      a = 2;
      b = 3;
    }
    cout << a << ' ' << b;
    n -= 2;
  }
  int i = 0;
  for (i = 2; n > 1; i += 2) {
    if (i == a || (i + 1) == a || i == b || (i + 1) == b) {
      i--;
      continue;
    }
    cout << ' ' << i << ' ' << i + 1;
    n -= 2;
  }
  if (n == 1) {
    if (a == 1 || b == 1) {
      while (1) {
        if (a != i && b != i) {
          cout << ' ' << i;
          break;
        }
        i++;
      }
    } else
      cout << ' ' << '1';
  }
  cout << '\n';
  return 0;
}
