#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
inline int qpow(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) {
      ans *= a;
    }
    a *= a;
    n >>= 1;
  }
  return ans;
}
inline long long _qpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
inline long long ksm(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
const int maxnum = 1e6 + 5;
const int MAXN = (1 << 13) - 1;
set<int> st[maxnum];
int n;
int x;
int f[MAXN + 5];
void slove() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    st[x].insert(i);
  }
  for (int i = 0; i <= MAXN; i++) f[i] = 0x3f3f3f3f;
  f[0] = 0;
  for (int i = 0; i <= MAXN; i++) {
    for (int j = MAXN; j >= 0; j--) {
      auto it = st[i].upper_bound(f[j]);
      if (it != st[i].end()) {
        f[i ^ j] = min(f[i ^ j], *it);
      }
    }
  }
  vector<int> ans;
  for (int i = 0; i <= MAXN; i++) {
    if (f[i] != 0x3f3f3f3f) ans.push_back(i);
  }
  cout << ans.size() << "\n";
  for (int x : ans) cout << x << " ";
  cout << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  ;
  slove();
  return 0;
}
