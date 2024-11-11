#include <bits/stdc++.h>
using namespace std;
int n, ld[(int)(5e5 + 4)];
bitset<(int)(5e5 + 4)> used;
int main() {
  cin >> n;
  ld[1] = 1;
  for (int i = 2; i < n + 1; ++i) {
    ld[i] = 1;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        ld[i] = i / j;
        break;
      }
    }
  }
  sort(ld + 1, ld + n + 1);
  for (int i = 2; i < n + 1; ++i) cout << ld[i] << ' ';
  return 0;
}
