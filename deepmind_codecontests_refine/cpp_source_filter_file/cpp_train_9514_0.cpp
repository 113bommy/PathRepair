#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<int> nums, fact;
int a, b, n;
void precomp() {
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) fact[i] = 1ll * fact[i - 1] * i % mod;
}
void gener() {
  int _max = log10(max(a, b) * n);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    nums.push_back(top);
    if ((int)log10(top) == _max) continue;
    for (int i : {a, b}) q.push(10 * top + i);
  }
}
void egcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  int x1, y1;
  egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
}
int inv_mod(int a) {
  int x, y;
  egcd(a, mod, x, y);
  return (x + mod) % mod;
}
int binom(int n, int k) {
  int top = fact[n];
  int bot = 1ll * fact[k] * fact[n - k];
  return 1ll * top * inv_mod(bot) % mod;
}
int main() {
  cin >> a >> b >> n;
  precomp();
  gener();
  int ans = 0;
  for (int c : nums) {
    int top = c - b * n;
    int bot = a - b;
    if (top % bot) continue;
    int res = top / bot;
    if (res >= 0 && res <= n) ans = (ans + binom(n, res)) % mod;
  }
  cout << ans << endl;
}
