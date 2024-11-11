#include <bits/stdc++.h>
using namespace std;
vector<long long> x, y;
inline long long Compare(const long long &a, const long long &b,
                         const long long &n) {
  return 6 * n - 3 * a * a * b + a * a * a - 3 * a * b - a;
}
long long Gao(const long long &n, const long long &a) {
  if (n < a) {
    return -1;
  }
  long long b = (6 * n + a * a * a - a) / (3 * a * a + 3 * a);
  long long res = Compare(a, b, n);
  if (0 == res) {
    return b;
  } else {
    return -1;
  }
}
int main() {
  long long n;
  ios::sync_with_stdio(0);
  while (cin >> n) {
    x.clear();
    y.clear();
    x.push_back(1);
    y.push_back(n);
    for (long long a = 2; a <= 1000000; ++a) {
      long long b = Gao(n, a);
      if (b > 0) {
        if (a > b) {
          break;
        }
        x.push_back(a);
        y.push_back(b);
      }
    }
    if (*x.rbegin() != *y.rbegin()) {
      cout << (x.size() * 2) << endl;
      for (int i = 0; i < x.size(); ++i) {
        cout << x[i] << ' ' << y[i] << endl;
      }
    } else {
      cout << (x.size() * 2 - 1) << endl;
      for (int i = 0; i < x.size() - 1; ++i) {
        cout << x[i] << ' ' << y[i] << endl;
      }
    }
    for (int i = x.size() - 1; i >= 0; --i) {
      cout << y[i] << ' ' << x[i] << endl;
    }
  }
  return 0;
}
