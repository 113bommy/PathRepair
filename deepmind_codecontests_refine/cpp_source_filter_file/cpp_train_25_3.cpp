#include <bits/stdc++.h>
#pragma warning(disable : 4996)
template <typename T>
T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T max(T x, T y) {
  return x > y ? x : y;
};
const long long INF = 20000000050000;
const long long mod = 998244353;
const long long MAXN = 205;
int N;
char s[MAXN][MAXN];
void invert(char ch) {
  if (s[1][3] != ch) printf("1 3\n");
  if (s[2][2] != ch) printf("2 2\n");
  if (s[3][1] != ch) printf("3 1\n");
}
void solve() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%s", s[i] + 1);
  int cnt = 0;
  cnt = (s[1][3] == '1') + (s[2][2] == '1') + (s[3][1] == '1');
  if (s[1][2] == s[2][1]) {
    if ((cnt == 0 || cnt == 3)) {
      if (s[1][2] == s[1][3]) {
        printf("2\n");
        printf("1 2\n");
        printf("2 1\n");
      } else
        printf("0\n");
    } else {
      if (s[1][2] == '1') {
        printf("%d\n", cnt);
        invert('0');
      } else {
        printf("%d\n", 3 - cnt);
        invert('1');
      }
    }
  } else {
    if ((cnt == 0 || cnt == 3)) {
      printf("1\n");
      if (s[1][2] != s[1][3])
        printf("1 2\n");
      else
        printf("2 1\n");
    } else {
      printf("2\n");
      if (cnt == 2)
        invert('1');
      else
        invert('0');
      char t = (cnt == 2 ? '1' : '0');
      if (s[1][2] == t)
        printf("1 2\n");
      else
        printf("2 1\n");
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
