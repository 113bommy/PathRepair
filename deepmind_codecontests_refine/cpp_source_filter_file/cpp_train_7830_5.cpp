#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-6;
int di[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
inline long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n;
char s[maxn];
int ans = 0;
int main() {
  n = rd();
  scanf("%s", s + 1);
  int cnt = 0;
  for (int i = 1; s[i]; i++) cnt += (s[i] == '(');
  if (cnt * 2 != n) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int total = 0;
    for (int j = i; j <= n; j++) {
      if (s[j] == '(')
        total++;
      else
        total--;
      if (total == 0) {
        if (s[i] == ')') ans += j - i + 1;
        i = j;
        break;
      }
    }
  }
  printf("%lld\n", ans);
}
