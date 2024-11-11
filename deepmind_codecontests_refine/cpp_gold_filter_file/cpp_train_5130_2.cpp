#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 10;
const int inf = 1e9;
int n, arr[N];
ll f[35][3];
void solve(int bit, vector<int> v) {
  if (bit < 0 || v.empty()) return;
  vector<int> v1, v2;
  ll ones = 0, zeros = 0;
  for (int x : v) {
    if (x & (1 << bit)) {
      ones++;
      f[bit][1] += zeros;
      v1.push_back(x);
    } else {
      zeros++;
      f[bit][0] += ones;
      v2.push_back(x);
    }
  }
  solve(bit - 1, v1), solve(bit - 1, v2);
}
int main() {
  cin >> n;
  vector<int> v(n);
  for (int I = (0); I <= (n - 1); I++) cin >> v[I];
  solve(31, v);
  ll ans = 0, inv = 0;
  for (ll i = 0; i < 32; i++) {
    if (f[i][1] < f[i][0]) {
      ans |= (1LL << i);
      inv += (ll)f[i][1];
    } else
      inv += (ll)f[i][0];
  }
  printf("%lld %lld\n", inv, ans);
  return 0;
}
