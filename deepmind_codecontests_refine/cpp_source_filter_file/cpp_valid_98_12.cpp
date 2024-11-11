#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b /= 2;
  }
  return res;
}
int main() {
  int test = 1, n;
  char s[100];
  scanf("%d", &test);
  while (test--) {
    int l = -1, r = -1;
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        cnt += (s[j] == 'a');
        cnt -= (s[j] == 'b');
        if (cnt == 0) {
          l = i, r = j;
          break;
        }
      }
      if (l != -1) {
        break;
      }
    }
    printf("%d %d\n", l, r);
  }
  return 0;
}
