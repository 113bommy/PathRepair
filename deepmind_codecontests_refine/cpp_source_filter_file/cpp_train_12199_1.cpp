#include <bits/stdc++.h>
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
template <class T>
inline void read(T& x) {
  bool sign = 0;
  char c = getchar();
  while (c != '-' && (c > '9' || c < '0')) c = getchar();
  if (c == '-')
    x = 0, sign = 1;
  else
    x = c - '0';
  while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
  if (sign) x *= -1;
}
using namespace std;
const int maxn = 2e5 + 10;
char t[maxn], s[maxn];
int res1[maxn], res2[maxn];
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int len = 0;
  int len2 = strlen(t);
  int pos = 0;
  for (int i = 0; s[i]; ++i, ++len) {
    if (s[i] == t[pos]) res1[pos++] = i;
  }
  pos -= 1;
  for (int i = len - 1; i >= 0; --i) {
    if (pos >= 0 && s[i] == t[pos]) res2[pos--] = i;
  }
  int res = max(res1[0] + 1, len - res1[len2 - 1] - 1);
  res = max(res, max(res2[0] + 1, len - res2[len2 - 1] - 1));
  for (int i = 0; i < len2 - 1; ++i) {
    res = max(res, res2[i + 1] - res1[i] - 1);
  }
  printf("%d\n", res);
}
