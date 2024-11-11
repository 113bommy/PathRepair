#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long suffix[N], prefix[N];
long long a[N];
long long L[N];
void solved() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i >= 1; i--) suffix[i] = gcd(suffix[i + 1], a[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans = gcd(ans, lcm(suffix[i + 1], a[i]));
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solved();
  return 0;
}
