#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x *= f, void();
}
template <typename T>
void ckmax(T &a, T b) {
  a = b > a ? b : a;
}
template <typename T>
void ckmin(T &a, T b) {
  a = b < a ? b : a;
}
const int N = 1e6 + 5;
int n, m, a[4][N], f[N][8];
char ch[4][N];
inline bool check(int S, int T) {
  int a1 = S & 1, a2 = (S >> 1) & 1, a3 = (S >> 2) & 1;
  int b1 = T & 1, b2 = (T >> 1) & 1, b3 = (T >> 2) & 1;
  if (!((a1 + a2 + b1 + b2) & 1)) return false;
  if (!((a2 + a3 + b2 + b3) & 1)) return false;
  return true;
}
inline int calc(int x, int S) {
  int a1 = S & 1, a2 = (S >> 1) & 1, a3 = (S >> 2) & 1;
  return (a1 != a[1][x]) + (a2 != a[2][x]) + (a3 != a[3][x]);
}
int main() {
  read(n), read(m);
  if (n >= 4) {
    puts("-1");
    exit(0);
  }
  if (n == 1) {
    puts("0");
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
    for (int j = 1; j <= m; j++) {
      a[i][j] = ch[i][j] == '1' ? 1 : 0;
    }
  }
  if (n == 2) {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= m; i++) {
      ans1 += (a[1][i] + a[2][i] + i) & 1;
    }
    for (int i = 1; i <= m; i++) {
      ans2 += (a[1][i] + a[2][i] + i + 1) & 1;
    }
    printf("%d\n", min(ans1, ans2));
    exit(0);
  }
  memset(f, 0x3f, sizeof(f));
  for (int S = 0; S < 8; S++) {
    f[1][S] = calc(1, S);
  }
  for (int i = 2; i <= n; i++) {
    for (int S = 0; S < 8; S++) {
      int val = calc(i, S);
      for (int T = 0; T < 8; T++) {
        if (check(S, T)) {
          f[i][S] = min(f[i][S], f[i - 1][T] + val);
        }
      }
    }
  }
  printf("%d\n", *min_element(f[n], f[n] + 8));
  return 0;
}
