#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double pi = 3.1415926535897932384626;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int maxn = 1e6 + 5;
int sum[maxn];
char s1[maxn], s2[maxn];
int main() {
  scanf("%s%s", s1 + 1, s2 + 1);
  int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
  int cnt = 0;
  for (int i = 1; i <= len2; ++i) {
    if (s2[i] == '1') ++cnt;
  }
  cnt %= 2;
  for (int i = 1; i <= len1; ++i) {
    if (s1[i] == '1')
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }
  int ans = 0;
  for (int i = len2; i <= len1; ++i) {
    if ((sum[i] - sum[i - len2]) % 2 == cnt) ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
