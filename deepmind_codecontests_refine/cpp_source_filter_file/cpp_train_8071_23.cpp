#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
const int mod = 1000000007;
char c[maxn + 5];
int b[] = {1, 2, 4, 8, 16, 32};
int e[] = {1, 3, 9, 27, 81, 243};
int d[65];
int main() {
  scanf(" %s", &c);
  int l = strlen(c);
  for (int i = 0; i <= 63; ++i) {
    int x = i;
    d[i] = 0;
    for (int j = 5; j >= 0; --j) {
      if (x >= b[j])
        x -= b[j];
      else
        ++d[i];
    }
  }
  long long ans = 1;
  int x;
  for (int i = 0; i < l; ++i) {
    if (c[i] >= '0' && c[i] <= '9') {
      x = c[i] - '0';
    } else if (c[i] >= 'a' && c[i] <= 'z') {
      x = c[i] - 61;
    } else if (c[i] >= 'A' && c[i] <= 'Z') {
      x = c[i] - 55;
    } else if (c[i] == '-') {
      x = 62;
    } else {
      x = 63;
    }
    int y = d[x];
    ans = (ans * e[y]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
