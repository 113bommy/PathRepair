#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool scan_d(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
inline void out(int x) {
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 105;
char str[maxn];
int num[maxn];
int main() {
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    num[i] = str[i] - '0';
  }
  for (int i = 0; i < len; i++) {
    if (num[i] % 8 == 0) {
      printf("YES\n");
      printf("%d\n", num[i]);
      return 0;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      int sum = num[i] * 10 + num[j];
      if (sum % 8 == 0) {
        printf("YES\n");
        printf("%d\n", sum);
        return 0;
      }
    }
  }
  if (len > 3) {
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        for (int k = j + 1; k < len; k++) {
          int sum = num[i] * 100 + num[j] * 10 + num[k];
          if (sum % 8 == 0) {
            printf("YES\n");
            printf("%d\n", sum);
            return 0;
          }
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
