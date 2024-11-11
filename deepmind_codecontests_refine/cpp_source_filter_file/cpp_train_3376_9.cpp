#include <bits/stdc++.h>
using namespace std;
long long int a, b;
long long int f(long long int p, long long int q) {
  long long int z = a - p + 1;
  z *= z;
  z += p - 1;
  long long int y = b / q;
  long long int x = y * y * (q - (b % q)) + ((y + 1) * (y + 1) * (b % q));
  return z - x;
}
void g(long long int p, long long int q) {
  int lol = (q <= p) ? (0) : (1);
  long long int L = b % q;
  long long int S = q - b % q;
  int up = p + q;
  long long int szL = b / q;
  long long int szS = szL + 1;
  bool st = false;
  for (int i = 0; i < up; i++) {
    if (i % 2 == lol) {
      if (!st) {
        st = true;
        for (int i = 0; i < a - p + 1; i++) cout << "o";
      } else
        cout << "o";
    } else {
      if (L) {
        L--;
        for (int i = 0; i < szL; i++) cout << 'x';
      } else {
        S--;
        for (int i = 0; i < szS; i++) cout << 'x';
      }
    }
  }
}
int main() {
  cin >> a >> b;
  if (b == 0) {
    cout << a * a << "\n";
    while (a--) cout << 'o';
    return 0;
  }
  if (a == 0) {
    cout << -(b * b) << "\n";
    while (b--) cout << 'x';
    return 0;
  }
  long long int res = -2e18;
  long long int resp, resq;
  for (int p = 1; p <= a; p++) {
    long long int q = p - 1;
    long long int tmp;
    if (q) {
      tmp = f(p, q);
      if (res < tmp) res = tmp, resp = p, resq = q;
    }
    q = p;
    if (q) {
      tmp = f(p, q);
      if (res < tmp) res = tmp, resp = p, resq = q;
    }
    q = p + 1;
    if (q) {
      tmp = f(p, q);
      if (res < tmp) res = tmp, resp = p, resq = q;
    }
  }
  cout << res << "\n";
  g(resp, resq);
  return 0;
}
