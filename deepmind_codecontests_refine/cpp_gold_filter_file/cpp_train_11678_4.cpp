#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long massiv[N];
long long prefix[N][11];
long long prefix_normal[N];
signed main() {
  long long n, m, k;
  cin >> n;
  cin >> m >> k;
  long long max_size = 0;
  for (long long i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    long long summa = prefix_normal[i - 1] + a - (i / m - !(i % m) + 1) * k;
    for (long long g = 0; g < m; g++) {
      prefix[i][g] = prefix[i - 1][g];
      long long o = 0;
      if (i % m == 0) {
        if (g <= i % m) {
          o = summa - prefix[i - 1][g];
        } else {
          o = summa - prefix[i - 1][g] - k;
        }
      } else {
        if (g < i % m) {
          if (g == 0) {
            o = summa - prefix[i - 1][g];
          } else {
            o = summa - prefix[i - 1][g] - k;
          }
        } else {
          o = summa - prefix[i - 1][g];
        }
      }
      max_size = max(max_size, o);
    }
    prefix[i][(i) % m] =
        min(prefix[i - 1][(i) % m],
            prefix_normal[i - 1] + a - (i / m - !(i % m) + 1) * k);
    prefix_normal[i] = a + prefix_normal[i - 1];
  }
  cout << max_size << endl;
}
