#include <bits/stdc++.h>
using namespace std;
int const sz = 2e5;
const int oo = 0x3f3f3f3f;
const double EPS = 1e-6;
long long const MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int tc;
vector<long long> ans;
void solve(long long n, int f, int s) {
  if (n > 1e10) return;
  if (f || s) ans.push_back(n);
  solve(n * 10 + 4, f + 1, s);
  solve(n * 10 + 7, f, s + 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ans.push_back(0);
  solve(4, 1, 0);
  solve(7, 0, 1);
  int l, r;
  cin >> l >> r;
  sort(ans.begin(), ans.end());
  long long an = 0;
  for (int i = 1; i < ans.size(); i++) {
    if (ans[i] >= r) {
      int res = max((long long)l - 1, ans[i - 1]);
      an += ans[i] * (r - res);
      break;
    }
    if (ans[i] >= l)
      an += ans[i] * (ans[i] - max((long long)l - 1, ans[i - 1]));
  }
  cout << an;
}
