#include <bits/stdc++.h>
using namespace std;
int n, ld[(int)(5e5 + 4)];
bitset<(int)(5e5 + 4)> used;
int main() {
  cin >> n;
  ld[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    ld[i] = 1;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        ld[i] = n / i;
        break;
      }
    }
  }
  sort(ld + 1, ld + n + 1);
  for (int i = 2; i < n + 1; ++i) cout << ld[i] << ' ';
  return 0;
}
