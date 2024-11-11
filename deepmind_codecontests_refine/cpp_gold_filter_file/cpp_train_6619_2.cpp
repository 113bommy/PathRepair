#include <bits/stdc++.h>
long long int maxx(long long int a, long long int b) { return a > b ? a : b; }
long long int minn(long long int a, long long int b) { return a > b ? b : a; }
using namespace std;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, -1, 0, 1, -1, 0};
void boostIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int poww(long long int base, long long int exp) {
  base %= 1000000007;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
int main() {
  boostIO();
  int n;
  cin >> n;
  int ans = 0;
  int cnt = 0;
  bool vis[100100] = {0};
  for (int i = 0; i < 2 * n; i++) {
    int x;
    cin >> x;
    if (!vis[x])
      cnt++, vis[x] = 1;
    else
      cnt--;
    ans = max(ans, cnt);
  }
  cout << ans;
}
