#include <bits/stdc++.h>
using namespace std;
const int N = 1205;
int n, x[N], id[N];
int main() {
  scanf("%d", &n);
  n *= 6;
  for (int i = (1); i <= (n / 2); ++i) {
    int k1;
    scanf("%d", &k1);
    x[k1] = 1;
  }
  for (int i = (1); i <= (n); ++i) id[i] = i;
  int cur = 1;
  for (int _ = n / 3; _; --_, n -= 3, cur ^= 1) {
    int lb = 1, rb = n;
    for (int i = 1, j; i <= n; i = j) {
      j = i + 1;
      while (j <= n && x[i] == x[j]) ++j;
      if ((j - i) % 3) {
        lb = i;
        break;
      }
    }
    for (int i = n, j; i >= 1; i = j) {
      j = i - 1;
      while (j >= 1 && x[i] == x[j]) --j;
      if ((i - j) % 3) {
        rb = i;
        break;
      }
    }
    int pos = -1;
    for (int i = (lb); i <= (rb - 2); ++i) {
      if (x[i] == cur && x[i + 1] == cur && x[i + 2] == cur) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      for (int i = (0); i <= (n - 2); ++i) {
        if (x[i] == cur && x[i + 1] == cur && x[i + 2] == cur) {
          pos = i;
          break;
        }
      }
    }
    printf("%d %d %d\n", id[pos], id[pos + 1], id[pos + 2]);
    for (int i = (pos); i <= (n - 2); ++i) {
      x[i] = x[i + 3];
      id[i] = id[i + 3];
    }
  }
  return 0;
}
