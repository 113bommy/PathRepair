#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 6, P = 1e9 + 7, H = 137;
int h[MAXN], bh[MAXN], pwh[MAXN], dp[MAXN];
string s;
int n;
void input();
int mul(int, int);
int sum(int, int);
void solve();
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input();
  solve();
  return 0;
}
void input() {
  cin >> s;
  n = s.size();
  pwh[0] = 1;
  for (int i = 1; i <= n; i++) pwh[i] = mul(pwh[i - 1], H);
}
int mul(int a, int b) { return 1ll * a * b % P; }
int sum(int a, int b) { return (P + a + b) % P; }
int get(int l, int r) { return sum(h[r], -mul(h[l], pwh[r - l])); }
void solve() {
  for (int i = 0; i < n; i++) h[i + 1] = sum(mul(h[i], H), int(s[i]) + 1);
  for (int i = n - 1; i >= 0; i--)
    bh[i] = sum(mul(bh[i + 1], H), int(s[i]) + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (get(0, i) == sum(bh[0], -mul(bh[i], pwh[i]))) {
      int mid = i / 2;
      dp[i] = 1;
      if (get(0, mid) == get(n - mid, n)) dp[i] += dp[mid];
      ans += dp[i];
    }
  cout << ans << endl;
}
