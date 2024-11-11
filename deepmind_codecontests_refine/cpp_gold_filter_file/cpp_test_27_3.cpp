#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
const int N = 2e5 + 9;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (n == 1 && m == 0 && k >= 2)
      puts("YES");
    else if (m < n - 1)
      puts("NO");
    else if (n * (n - 1) / 2 < m)
      puts("NO");
    else if (m >= n - 1 && n * (n - 1) / 2 > m) {
      if (k - 1 > 2)
        puts("YES");
      else
        puts("NO");
    } else if (m >= n - 1 && n * (n - 1) / 2 == m) {
      if (k - 1 > 1)
        puts("YES");
      else
        puts("NO");
    }
  }
}
