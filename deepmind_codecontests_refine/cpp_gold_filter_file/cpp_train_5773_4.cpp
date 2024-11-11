#include <bits/stdc++.h>
const long double PI(acosl(-1.0));
long double eps = 1e-8;
using namespace std;
const int N = 100100;
int v[3];
int main() {
  cout.precision(10);
  int n, m;
  cin >> n >> m;
  if (n * m == 2) {
    cout << 0 << '\n';
    if (n == 2) {
      puts("1 1");
      puts("2 1");
      puts("1 1");
    } else {
      puts("1 1");
      puts("1 2");
      puts("1 1");
    }
    return 0;
  }
  if (n == 1) {
    cout << 1 << '\n';
    cout << n << ' ' << m << ' ' << "1 1\n";
    for (int i = 1; i <= m; ++i) {
      cout << 1 << ' ' << i << '\n';
    }
    cout << "1 1";
    return 0;
  }
  if (m == 1) {
    cout << 1 << '\n';
    cout << n << ' ' << m << ' ' << "1 1\n";
    for (int i = 1; i <= n; ++i) {
      cout << i << ' ' << 1 << '\n';
      ;
    }
    cout << "1 1";
    return 0;
  }
  if (n % 2 == 0) {
    cout << 0 << '\n';
    for (int i = 1; i <= n; ++i) cout << i << ' ' << 1 << '\n';
    for (int i = n; i; --i) {
      if (i % 2 == 0)
        for (int j = 2; j <= m; ++j) cout << i << ' ' << j << '\n';
      else
        for (int j = m; j >= 2; --j) cout << i << ' ' << j << '\n';
    }
    cout << "1 1";
    return 0;
  }
  if (m % 2 == 0) {
    cout << 0 << '\n';
    for (int i = 1; i <= m; ++i) cout << 1 << ' ' << i << '\n';
    for (int i = m; i; --i) {
      if (i % 2 == 0)
        for (int j = 2; j <= n; ++j) cout << j << ' ' << i << '\n';
      else
        for (int j = n; j >= 2; --j) cout << j << ' ' << i << '\n';
    }
    cout << "1 1";
    return 0;
  }
  cout << 1 << '\n';
  cout << n << ' ' << m << ' ' << "1 1\n";
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 1)
      for (int j = 1; j <= m; ++j) cout << i << ' ' << j << '\n';
    else
      for (int j = m; j >= 1; --j) cout << i << ' ' << j << '\n';
  }
  cout << "1 1";
}
