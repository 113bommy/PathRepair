#include <bits/stdc++.h>
using namespace std;
long long f(long long n) { return n * (n + 1) / 2; }
int main() {
  long long n, m;
  while (cin >> n >> m) {
    if (n > m) {
      long long i = 0, j = 1e9, y;
      long long aux = n - m;
      while (i <= j) {
        y = (j + i) / 2;
        if (f(y) >= aux)
          j = y - 1;
        else
          i = y + 1;
      }
      cout << j + m + 1 << endl;
    } else
      cout << m << endl;
  }
}
