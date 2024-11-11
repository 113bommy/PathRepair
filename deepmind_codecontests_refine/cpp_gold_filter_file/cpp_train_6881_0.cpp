#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const long long mod = 1000000007;
int a[N], sta[N], top;
int l[N], r[N];
void add(long long &x, long long y) {
  x += y;
  while (x >= mod) x -= mod;
}
int neq(int a, int K, int ff) {
  if (ff == 1) return (a - 1) / (K - 1) + 1;
}
long long cal0(long long f, long long n, long long d) {
  if (n <= 0) return 0ll;
  long long g = (f + (n - 1) * d) % mod;
  return ((f + g) * n / 2) % mod;
}
long long cal(int l, int r, int i, int K) {
  if (i - l > r - i) i = r - (i - l);
  long long tm = neq(r - l + 1, K, 1);
  long long tl = neq(i - l + 1, K, 1), tr = neq(r - i + 1, K, 1);
  long long ll = i - l + 1, rr = r - i + 1, mm = r - l + 1;
  long long ans1 = cal0(K, tl - 1, K - 1);
  long long ans2 = ll * (tr - tl) % mod;
  long long f = (mm - (tr * K - tr + 1) + 1) % mod;
  long long n = tm - tr;
  long long ans3 = cal0(f, n, mod - (K - 1));
  return (ans1 + ans2 + ans3) % mod;
}
int main() {
  int i, n, K;
  cin >> n >> K;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    while (top && a[i] > a[sta[top]]) r[sta[top]] = i - 1, top--;
    l[i] = sta[top] + 1, sta[++top] = i;
  }
  for (i = 1; i <= top; i++) r[sta[i]] = n;
  long long ans = 0;
  for (i = 1; i <= n; i++) add(ans, cal(l[i], r[i], i, K) * a[i] % mod);
  cout << ans << endl;
  return 0;
}
