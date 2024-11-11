#include <bits/stdc++.h>
using namespace std;
int n;
char str[200010];
int phi[200010];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
bool chk[200010];
bool valid(int c) {
  int i, t, su;
  for (i = 0; i < n; ++i) chk[i] = false;
  for (i = 0; i < n; ++i) {
    if (chk[i]) continue;
    t = i;
    su = 0;
    while (!chk[t]) {
      su += (str[t] - '0');
      chk[t] = true;
      t = (t + c) % n;
    }
    if (su % 2) return false;
  }
  return true;
}
int main() {
  int i, ans = 0;
  scanf("%d", &n);
  scanf("%s", str);
  for (i = 0; i < n; ++i) {
    if (str[i] == '1') break;
  }
  if (i >= n) ++ans;
  phi[1] = 0;
  for (i = 1; i < n; ++i) ++phi[n / gcd(n, i)];
  for (i = 1; i < n; ++i) {
    if (n % i) continue;
    if (valid(i)) ans += phi[n / i];
  }
  printf("%d\n", ans);
}
