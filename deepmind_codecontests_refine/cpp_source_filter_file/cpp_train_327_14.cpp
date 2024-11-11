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
char s[maxn];
long long prex[maxn], prey[maxn];
int main() {
  int t;
  for (read(t); t--;) {
    scanf("%s", s + 1);
    int len = 0;
    int mx[2][2] = {0, 0, 0, 0}, my[2][2] = {0, 0, 0, 0};
    for (int i = 1; s[i]; ++i, ++len) {
      prex[i] = prey[i] = 0;
      switch (s[i]) {
        case 'W':
          prex[i] = 1;
          break;
        case 'S':
          prex[i] = -1;
          break;
        case 'D':
          prey[i] = 1;
          break;
        case 'A':
          prey[i] = -1;
          break;
      }
      prex[i] += prex[i - 1];
      prey[i] += prey[i - 1];
      if (prex[i] < prex[mx[0][0]])
        mx[0][0] = mx[0][1] = i;
      else if (prex[i] == prex[mx[0][1]])
        mx[0][1] = i;
      if (prex[i] > prex[mx[1][0]])
        mx[1][0] = mx[1][1] = i;
      else if (prex[i] == prex[mx[1][1]])
        mx[1][1] = i;
      if (prey[i] < prey[my[0][0]])
        my[0][0] = my[0][1] = i;
      else if (prey[i] == prey[my[0][1]])
        my[0][1] = i;
      if (prey[i] > prey[my[1][0]])
        my[1][0] = my[1][1] = i;
      else if (prey[i] == prey[my[1][1]])
        my[1][1] = i;
    }
    long long res = (prex[mx[1][0]] - prex[mx[0][0]] + 1ll) *
                    (prey[my[1][0]] - prey[my[0][0]] + 1ll);
    if (mx[1][0] > mx[0][1] || mx[1][1] < mx[0][0])
      res = min(res, max(2ll, (prex[mx[1][0]] - prex[mx[0][0]])) *
                         (prey[my[1][0]] - prey[my[0][0]] + 1ll));
    if (my[1][0] > my[0][1] || my[1][1] < my[0][0])
      res = min(res, (prex[mx[1][0]] - prex[mx[0][0]] + 1ll) *
                         max(2ll, (prey[my[1][0]] - prey[my[0][0]])));
    printf("%d\n", res);
  }
}
