#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int M = 998244353;
const int N = 3e5 + 5;
int dp[N];
int n, k;
int fast_exp(int a, int b) {
  if (b == 0) {
    return 1;
  } else if (b & 1) {
    ll x = fast_exp(a, (b - 1) / 2);
    return (a * ((x * x) % M)) % M;
  } else {
    ll x = fast_exp(a, b / 2);
    return (x * x) % M;
  }
}
ll modfac(int a) {
  if (a == 0) {
    return 1;
  } else if (dp[a] != -1) {
    return dp[a];
  } else {
    ll ans = (a * modfac(a - 1)) % M;
    dp[a] = ans;
    return ans;
  }
}
int nck(int a, int b) {
  if (a < b) {
    return 0;
  }
  ll x = modfac(a);
  ll y = modfac(b);
  ll z = modfac(a - b);
  ll l = (y * z) % M;
  ll inv = fast_exp(l, M - 2);
  return (x * inv) % M;
}
int main() {
  cin >> n >> k;
  vector<array<int, 4>> sweep{};
  for (int i = 0; i < n; ++i) {
    dp[i] = -1;
    int l, r;
    cin >> l >> r;
    sweep.push_back({l, 0, r, 1});
    sweep.push_back({r, 1, l, -1});
  }
  dp[n] = -1;
  sort(sweep.begin(), sweep.end());
  int size = 0;
  ll ans = 0;
  for (int i = 0; i < (int)sweep.size(); ++i) {
    int action = sweep[i][3];
    if (action == 1) {
      int curr = nck(size, k - 1);
      ans = (ans + curr) % M;
      size += 1;
    } else if (action == -1) {
      size -= 1;
    }
  }
  cout << ans << endl;
}
