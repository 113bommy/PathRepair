#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
char gc() {
  char c;
  while (isspace(c = getchar()))
    ;
  return c;
}
int gs(char* s) {
  gets(s);
  int l = strlen(s);
  while (l && isspace(s[l - 1])) s[--l] = 0;
  return l;
}
int a[2010], mx[2010], dp[2010];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= m; i++) dp[i] = i;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) mx[i] = max(mx[i + 1], a[i]);
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = max(ans, mx[i + 1] * (m / a[i]) + (m % a[i]));
  cout << ans;
}
