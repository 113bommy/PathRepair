#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  clock_t t1, t2;
  t1 = clock();
  char digits[20] = {0};
  sprintf(digits, "%d\n", n);
  int n_d = 0;
  int dig[10] = {0};
  for (; digits[n_d] != '\n'; n_d++) {
    dig[digits[n_d] -= '0'] = 1;
  }
  int count = 1;
  int n2 = n >> 1;
  int n3 = n / 3;
  int n4 = n >> 2;
  for (int i = 1; i <= n4; ++i) {
    if (n % i == 0) {
      int c = i;
      do {
        int o = c % 10;
        c /= 10;
        if (dig[o]) {
          count++;
          break;
        }
      } while (c);
    }
  }
  if (n3 && n % n3 == 0) {
    int c = n3;
    do {
      int o = c % 10;
      c /= 10;
      if (dig[o]) {
        count++;
        break;
      }
    } while (c);
  }
  if (n4 && n % n4 == 0) {
    int c = n4;
    do {
      int o = c % 10;
      c /= 10;
      if (dig[o]) {
        count++;
        break;
      }
    } while (c);
  }
  t2 = clock();
  cout << endl << count;
  return 0;
}
