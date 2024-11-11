#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1200000 + 5;
const int mod = (int)1e9 + 7;
long long fac[maxn], inv[maxn];
long long C(int n, int k) {
  if (n < k || k < 0) return 0;
  return ((fac[n] * inv[n - k] % mod) * inv[k]) % mod;
}
long long pw(long long a, int b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int BIT[maxn];
void update(int x, int val) {
  while (x > 0) {
    BIT[x] += val;
    x -= x & -x;
  }
}
int get(int x) {
  int res = 0;
  while (x < maxn) {
    res += BIT[x];
    x += x & -x;
  }
  return res;
}
int n, k, cur;
vector<pair<int, int> > a;
set<int> S;
vector<int> b;
map<int, int> mp;
long long solve(int l, int r) {
  if (l > r) return 0;
  while (a[cur].first <= l && cur < n) {
    update(mp[a[cur].second], 1);
    cur++;
  }
  int cnt = get(mp[r]);
  long long res = (C(cnt, k) * (r - l + 1)) % mod;
  return res;
}
int main() {
  long long res = 0;
  fac[0] = inv[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv[i] = pw(fac[i], mod - 2);
  }
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    S.insert(a[i].first);
    S.insert(a[i].second);
    S.insert(a[i].first + 1);
    S.insert(a[i].second + 1);
    S.insert(a[i].first - 1);
    S.insert(a[i].second - 1);
    b.push_back(a[i].first);
    b.push_back(a[i].second);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  int id = 0;
  for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
    mp[*it] = ++id;
  }
  for (int i = 0; i < b.size(); i++) {
    if (i > 0) {
      res += solve(b[i - 1] + 1, b[i] - 1);
    }
    res += solve(b[i], b[i]);
    res %= mod;
  }
  cout << res << endl;
}
