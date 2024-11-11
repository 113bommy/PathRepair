#include <bits/stdc++.h>
using namespace std;
long long a[500010], sum[500010], ss[510010];
bool isvowel(char C) {
  if (C == 'A' || C == 'E' || C == 'I' || C == 'O' || C == 'U' || C == 'Y')
    return true;
  return false;
}
int main() {
  int i, j, k, n;
  long long t;
  string s;
  double ans = 0.0;
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) a[i] = isvowel(s[i]);
  sum[0] = 0;
  for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
  ss[0] = 0;
  for (i = 1; i <= n; i++) ss[i] = ss[i - 1] + sum[i];
  for (int len = 1; len <= n; len++) {
    t = ss[n] - ss[len - 1] - ss[n - len];
    ans += (double)t / len;
  }
  printf("%.7lf\n", ans);
  return 0;
}
