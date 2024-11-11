#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, d[100001];
  scanf("%d %d\n", &n, &k);
  d[0] = 0;
  d[n + 1] = 0;
  char sym;
  for (int i = 1; i < n + 1; i++) {
    scanf("%c", &sym);
    d[i] = sym - '0';
    if (i != 1 && k != 0) {
      if (d[i] == 7 && d[i - 1] == 4 && d[i - 2] != 4 && i % 2 == 1) {
        if (k > 0) {
          d[i - 1] = 7;
          d[i] = 7;
          k--;
        }
      } else if (d[i] == 7 && d[i - 1] == 4 && i % 2 == 0) {
        if (k > 0) {
          d[i - 1] = 4;
          d[i] = 4;
          k--;
        }
      } else if (d[i] == 7 && d[i - 1] == 4 && d[i - 2] == 4 && i % 2 == 1) {
        if (k % 2 == 0)
          k = 0;
        else {
          d[i - 1] = 7;
          d[i - 2] = 4;
          k = 0;
        }
      }
    }
  }
  for (int i = 1; i < n + 1; i++) {
    printf("%d", d[i]);
  }
  return 0;
}
