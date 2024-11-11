#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;
char buf[100];
long long phi(long long x) {
  sprintf(buf, "%I64d", x);
  for (int i = 0; i < (int)(strlen(buf)); i++)
    buf[i] = (9 - (buf[i] - '0')) + '0';
  sscanf(buf, "%I64d", &x);
  return x;
}
long long f(long long x) { return x * phi(x); }
long long solve(long long l, long long r) {
  while (r - l > 10) {
    long long mid1 = (2 * l + r) / 3;
    long long mid2 = (l + 2 * r) / 3;
    if (f(mid1) < f(mid2))
      l = mid1;
    else
      r = mid2;
  }
  long long ans = 0;
  for (long long x = l; x <= r; x++) ans = max(ans, f(x));
  return ans;
}
int main() {
  long long l, r;
  cin >> l >> r;
  long long pw = 1, ans = 0;
  for (int i = 0; i < (int)(11); i++) {
    ans = max(ans, solve(max(pw, l), min(r, pw * 10 - 1)));
    pw *= 10;
  }
  cout << ans << endl;
  return 0;
}
