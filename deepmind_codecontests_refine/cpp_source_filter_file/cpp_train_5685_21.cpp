#include <bits/stdc++.h>
using namespace std;
void z(long long m) {
  if (m == 2) {
    return;
  }
  z(m - 2);
  for (long long i = 1; i < m - 1; i += 2) {
    cout << 4 << ' ' << m << ' ' << i << ' ' << m - 1 << ' ' << i + 1 << endl;
  }
}
void f(long long m) {
  for (long long i = 1; i < m - 1; i += 2) {
    cout << 3 << ' ' << m << ' ' << i << ' ' << i + 1 << endl;
  }
  z(m - 1);
}
void zz(long long m) {
  if (m == 4) {
    cout << "4 1 2 4 3\n";
    return;
  }
  zz(m - 4);
  for (long long i = 1; i < m - 3; i += 2) {
    cout << 4 << ' ' << m << ' ' << i << ' ' << m - 1 << ' ' << i + 1 << endl;
  }
  for (long long i = 1; i < m - 3; i += 2) {
    cout << 4 << ' ' << m - 2 << ' ' << i << ' ' << m - 3 << ' ' << i + 1
         << endl;
  }
  cout << 4 << ' ' << m << ' ' << m - 1 << ' ' << m - 3 << ' ' << m - 2 << endl;
}
void tt(long long m) {
  for (long long i = 1; i <= m; i += 4) {
    cout << "4 " << i << ' ' << i + 1 << ' ' << i + 2 << ' ' << i + 3 << endl;
  }
}
int main() {
  long long m;
  cin >> m;
  if (m & 1) {
    long long u = m / 2;
    cout << 2 * (u + u * (u - 1) / 2) << endl;
    f(m);
    f(m);
  }
  if (m % 4 == 0) {
    long long u = m / 2;
    cout << u * (u - 1) + u / 2 << endl;
    ;
    z(m);
    zz(m);
    tt(m);
  }
  if (m % 4 == 2) {
    long long u = m / 2;
    long long p = u - 1;
    cout << u * (u - 1) / 2 + p * (p - 1) / 2 + p * 2 << endl;
    z(m);
    zz(m - 2);
    for (long long i = 5; i < m - 1; i += 4) {
      cout << "3 " << m << ' ' << i << ' ' << i + 1 << endl;
      cout << "3 " << m << ' ' << i + 2 << ' ' << i + 3 << endl;
      cout << "3 " << m + 1 << ' ' << i << ' ' << i + 3 << endl;
      cout << "3 " << m + 1 << ' ' << i + 1 << ' ' << i + 2 << endl;
    }
    cout << "4 1 2 " << m << ' ' << m - 1 << endl;
    cout << 3 << ' ' << m << " 1 4\n";
    cout << 3 << ' ' << m - 1 << " 3 2\n";
    cout << 4 << ' ' << m << ' ' << m - 1 << " 4 3\n";
  }
}
