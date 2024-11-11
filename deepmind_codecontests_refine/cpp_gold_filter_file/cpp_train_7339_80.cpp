#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void upd_max(T& dest, const T& src) {
  if (dest < src) dest = src;
  return;
}
template <typename T>
inline void upd_min(T& dest, const T& src) {
  if (dest > src) dest = src;
  return;
}
const int maxN = 13;
char s[maxN][maxN];
int main() {
  for (int i = 1; i <= 8; i++) scanf("%s", &s[i][1]);
  int ansB = 10, ansW = 10;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (s[i][j] == 'B') {
        bool ok = true;
        for (int k = i + 1; k <= 8; k++)
          if (s[k][j] != '.') ok = false;
        if (ok && 8 - i != 0) upd_min(ansB, 8 - i);
      } else if (s[i][j] == 'W') {
        bool ok = true;
        for (int k = i - 1; k >= 1; k--)
          if (s[k][j] != '.') ok = false;
        if (ok && i != 1) upd_min(ansW, i - 1);
      }
    }
  }
  if (ansW <= ansB)
    printf("A\n");
  else
    printf("B\n");
  return 0;
}
