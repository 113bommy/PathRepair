#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e6 + 30;
const int MOD = (int)1e9 + 7;
int add(int a, int b) {
  int c = a + b;
  if (c >= MOD) c -= MOD;
  if (c < 0) c += MOD;
  return c;
}
int mul(int a, int b) {
  int c = 1LL * a * b % MOD;
  return c;
}
int pwr(int a, int b) {
  if (!b) return 1;
  int res = pwr(a, b >> 1);
  res = mul(res, res);
  if (b & 1) res = mul(res, a);
  return res;
}
int inv(int p) { return pwr(p, MOD - 2); }
int fact[MAXN], invfact[MAXN];
int C(int n, int k) {
  if (k == 0) {
    return 1;
  }
  int ans = fact[n];
  ans = mul(ans, invfact[k]);
  ans = mul(ans, invfact[n - k]);
  return ans;
}
vector<pair<int, int>> v;
void D(int a) {
  int cnt = 0;
  for (int i = 2; 1LL * i * i <= a; i++) {
    cnt = 0;
    while (a % i == 0) {
      cnt++;
      a /= i;
    }
    if (cnt >= 1) {
      bool is = true;
      for (int j = 0; j < v.size(); j++) {
        if (v[j].first == i) {
          v[j].second += cnt;
          is = false;
          break;
        }
      }
      if (is) {
        pair<int, int> h;
        h.first = i;
        h.second = cnt;
        v.push_back(h);
      }
    }
  }
  if (a > 1) {
    bool is = true;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].first == a) {
        v[j].second++;
        is = false;
        break;
      }
    }
    if (is) {
      pair<int, int> h;
      h.first = a;
      h.second = 1;
      v.push_back(h);
    }
  }
  return;
}
long long res = 1, sum = 0, n, a, cnt = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i);
  for (int i = 0; i < MAXN; i++) invfact[i] = inv(fact[i]);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    D(a);
  }
  for (int i = 0; i < v.size(); i++) {
    res = mul(res, C(v[i].second + n - 1, n - 1));
  }
  cout << res % MOD;
}
