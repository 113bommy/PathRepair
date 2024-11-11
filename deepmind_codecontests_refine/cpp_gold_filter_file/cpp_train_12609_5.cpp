#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmax(T& x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmin(T& x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T& x) {
  char c;
  int sign = 1;
  x = 0;
  do {
    c = getchar();
    if (c == '-') sign = -1;
  } while (!isdigit(c));
  do {
    x = x * 10 + c - '0';
    c = getchar();
  } while (isdigit(c));
  x *= sign;
}
const int N = 5e5 + 50;
int n, k;
long long ans;
char s1[N], s2[N];
int main() {
  read(n);
  read(k);
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  bool e = 0;
  --k;
  long long now = 0;
  for (register int i = 1; i <= n; ++i)
    if (s1[i] != s2[i] && !e) {
      e = 1;
      --k;
      ans += 2 * (n - i + 1);
      if (!k) break;
    } else if (e) {
      if (k > now)
        k -= now, ans += now * (n - i + 1);
      else {
        ans += 1ll * k * (n - i + 1);
        break;
      }
      now <<= 1;
      if (s2[i] == 'b') {
        --k;
        ++now;
        ans += (n - i + 1);
      }
      if (!k) break;
      if (s1[i] == 'a') {
        --k;
        ++now;
        ans += (n - i + 1);
      }
      if (!k) break;
    } else
      ++ans;
  printf("%I64d\n", ans);
  return 0;
}
