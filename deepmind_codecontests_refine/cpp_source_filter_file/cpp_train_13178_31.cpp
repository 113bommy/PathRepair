#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
template <class T>
inline void read(T& x) {
  int sign = 1;
  char c = getchar();
  x = 0;
  while (c > '9' || c < '0') {
    if (c == '-') sign = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= sign;
}
using namespace std;
const int maxn = 5e6 + 10;
unsigned long long ji = 1;
long long dp[maxn];
unsigned long long prehash[maxn], sufhash[maxn];
char s[maxn];
inline int val(char x) {
  if (x >= '0' && x <= '9') return x - '0';
  if (x >= 'a' && x <= 'z') return x - 'a' + 10;
  if (x >= 'A' && x <= 'Z') return x - 'Z' + 36;
}
int main() {
  scanf("%s", s + 1);
  int len = 0;
  for (int i = 1; s[i]; ++i) s[i] = val(s[i]);
  for (int i = 1; s[i]; ++i) prehash[i] = prehash[i - 1] * 131 + 1ll * s[i];
  for (int i = 1; s[i]; ++i) {
    sufhash[i] = sufhash[i - 1] + 1ll * s[i] * ji;
    ji *= 131;
  }
  long long res = 0;
  for (int i = 1; i <= len; ++i) {
    if (prehash[i] == sufhash[i]) {
      dp[i] = dp[i >> 1] + 1;
    }
    res += dp[i];
  }
  printf("%lld\n", res);
}
