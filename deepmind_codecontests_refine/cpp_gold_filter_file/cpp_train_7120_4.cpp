#include <bits/stdc++.h>
using namespace std;
char shuru[110][110];
bool r[110], c[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", shuru[i]);
  int cc = 0, rr = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (shuru[i][j] == '.') {
        if (!r[i]) {
          rr++;
          r[i] = true;
        }
        if (!c[j]) {
          cc++;
          c[j] = true;
        }
      }
    }
  if (cc < n && rr < n)
    printf("-1\n");
  else {
    if (cc == n) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (shuru[j][i] == '.') {
            printf("%d %d\n", j + 1, i + 1);
            break;
          }
        }
      }
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (shuru[i][j] == '.') {
            printf("%d %d\n", i + 1, j + 1);
            break;
          }
        }
      }
    }
  }
  return 0;
}
