#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
int n;
char s[N];
int res[N];
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'L') {
      for (int j = 0; j < 9; ++j) {
        if (!res[j]) {
          res[j] = 1;
          break;
        }
      }
    } else if (s[i] == 'R') {
      for (int j = 9; j >= 0; --j) {
        if (!res[j]) {
          res[j] = 1;
          break;
        }
      }
    } else
      res[s[i] - '0'] = 0;
  }
  for (int i = 0; i < 10; ++i) printf("%d", res[i]);
  printf("\n");
  return 0;
}
