#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[18] = {1,   2,    4,    8,    16,   32,    64,    128,   256,
               512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 100001};
  int n;
  cin >> n;
  for (int i = 1; i <= 17; i++) {
    if (n == a[i]) {
      cout << i + 1;
      return 0;
    }
  }
  int i = 17;
  while ((i >= 0) && (n > 0)) {
    if (n >= a[i]) {
      cout << a[i] << ' ';
      n -= a[i];
    }
    i--;
  }
  return 0;
}
