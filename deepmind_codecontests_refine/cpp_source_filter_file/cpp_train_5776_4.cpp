#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 10;
char c[N];
int a[N], p[N], s[N], d[N];
bool check(char x) {
  if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y')
    return true;
  else
    return false;
}
int main() {
  scanf("%s", c);
  int n = strlen(c), t = 0;
  for (int i = 0; i < n; i++)
    if (check(c[i])) a[i + 1] = 1, t++;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
  for (int i = n; i >= 1; i--) s[i] = s[i + 1] + a[i];
  for (int i = 1; i <= n; i++) d[i] = d[i - 1] + p[i] + s[n - i + 1];
  double ans = 0.0;
  for (int i = 1; i <= n; i++) ans += (double)t - (double)d[i - 1] / (double)i;
  printf("%.7lf\n", ans);
  return 0;
}
