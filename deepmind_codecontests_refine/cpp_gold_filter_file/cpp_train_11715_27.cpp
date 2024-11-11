#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T alex(T x) {
  return (x > 0) ? x : -x;
}
template <class T>
void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while ((ch < 48 || ch > 57) && ch != 45) ch = getchar();
  if (ch == 45) f = -1, ch = getchar();
  while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
int n, k;
char s[1000005];
int f[26];
bool vis[26];
int que[26], cnt;
int main() {
  read(n);
  read(k);
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  f[s[1] - 'a'] = 1;
  int sum = 1;
  for (int i = (2); i <= (len); i++) {
    int all = f[s[i] - 'a'];
    f[s[i] - 'a'] = (sum + 1) % 1000000007;
    sum = (sum * 2 % 1000000007 + 1 - all + 1000000007) % 1000000007;
  }
  cnt = k;
  for (int i = (len); i >= (1); i--)
    if (!vis[s[i] - 'a']) vis[s[i] - 'a'] = true, que[--cnt] = s[i] - 'a';
  for (int i = (0); i < (k); i++)
    if (!vis[i]) que[--cnt] = i;
  for (int i = 1, j = 0; i <= n; i++, j = (j + 1) % k) {
    int all = f[que[j]];
    f[que[j]] = (sum + 1) % 1000000007;
    sum = (sum * 2 % 1000000007 + 1 - all + 1000000007) % 1000000007;
  }
  printf("%d\n", (sum + 1) % 1000000007);
  return 0;
}
