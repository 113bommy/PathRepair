#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
const int maxn = 100005;
int n;
long long zero = 0, one = 0, z1 = 0, o1 = 0;
char s[maxn], t[maxn];
int main() {
  n = read();
  scanf("%s%s", s, t);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      zero++;
      if (t[i] == '1') z1++;
    } else {
      one++;
      if (t[i] == '0') o1++;
    }
  }
  printf("%lld\n", z1 * one + o1 * zero - z1 * o1);
  return 0;
}
