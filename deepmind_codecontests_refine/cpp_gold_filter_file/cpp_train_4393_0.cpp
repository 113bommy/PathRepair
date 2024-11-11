#include <bits/stdc++.h>
using namespace std;
const int nmax = (int)1e5 + 3;
char c;
int n, k, t[nmax];
int main() {
  scanf("%d%d", &n, &k);
  scanf("%c", &c);
  for (int i = 1; i <= (int)n; ++i) {
    scanf("%c", &t[i]);
    t[i] -= '0';
  }
  for (int i = 1; i <= (int)n; ++i)
    if (k > 0 && t[i] == 4 && t[i + 1] == 7) {
      if (i & 1) {
        if (t[i + 2] == 7) {
          if (k & 1) t[i + 1] = 4;
          k = 0;
          if (0) printf("%d eternal\n", i);
        } else {
          t[i + 1] = 4;
          --k;
          if (0) printf("%d normal %d\n", i, k);
        }
      } else {
        if (t[i - 1] == 4) {
          if (k & 1) t[i] = 7;
          k = 0;
          if (0) printf("%d eternal\n", i);
        } else {
          t[i] = 7;
          --k;
          if (0) printf("%d normal %d\n", i, k);
        }
      }
    }
  for (int i = 1; i <= (int)n; ++i) printf("%c", t[i] + '0');
  return 0;
}
