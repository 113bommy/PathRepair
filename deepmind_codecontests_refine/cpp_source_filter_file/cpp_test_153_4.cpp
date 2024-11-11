#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wsign-compare"
int64_t divCeil(int64_t x, int64_t y) { return (x + y - 1) / y; }
vector<int64_t> readVec(int64_t n) {
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) cin >> a[i];
  return a;
}
int64_t M = 998244353LL;
vector<uint16_t> toCounts(string s) {
  vector<uint16_t> ans(26, 1);
  for (char c : s) ans[c - 'a']++;
  return ans;
}
int64_t bitCount(int64_t msk) {
  int64_t bitCnt = 0;
  while (msk != 0) {
    bitCnt += (msk % 2);
    msk /= 2;
  }
  return bitCnt;
}
int64_t maskCode(int64_t msk) {
  int64_t bitCnt = 0;
  int64_t idxSum = 0;
  for (int64_t i = 0; i <= 23; i++) {
    int64_t bit = msk % 2;
    msk /= 2;
    bitCnt += bit;
    idxSum += bit * (i + 1);
    if (msk == 0) break;
  }
  return bitCnt * idxSum;
}
int64_t msb(int64_t x) {
  int64_t ans = -1;
  while (x > 0) {
    x /= 2;
    ans++;
  }
  return ans;
}
int64_t lsb(int64_t x) {
  assert(x > 0);
  int64_t ans = 0;
  while (x % 2 == 0) {
    x /= 2;
    ans++;
  }
  return ans;
}
void solve() {
  int64_t n;
  cin >> n;
  vector<vector<uint16_t> > c;
  for (int64_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    c.push_back(toCounts(s));
  }
  int64_t N = 1LL << n;
  vector<vector<uint16_t> > cMins(N, vector<uint16_t>(26, (uint16_t)20000));
  vector<int64_t> f1(N, 0);
  f1[0] = 0;
  for (int64_t msk = 1; msk < N; msk++) {
    int64_t i = msb(msk);
    assert(i >= 0 && i < n);
    int64_t msk2 = msk - (1LL << i);
    int64_t prod = 1;
    for (int64_t j = 0; j < 26; j++) {
      uint16_t m = min(cMins[msk2][j], c[i][j]);
      cMins[msk][j] = m;
      prod = (prod * (int64_t)m) % M;
    }
    f1[msk] = prod;
  }
  for (int64_t msk = 1; msk < N; msk++) {
    if (bitCount(msk) % 2 == 0) f1[msk] = -f1[msk];
  }
  vector<int64_t> f(N, 0);
  for (int64_t i = 0; i < N; ++i) f[i] = f1[i];
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t mask = 0; mask < N; mask++) {
      if (mask & (1 << i)) f[mask] = (f[mask] + f[mask ^ (1 << i)]) % M;
    }
  }
  for (int64_t i = 0; i < N; i++) f[i] = (f[i] + M) % M;
  int64_t ans = 0;
  for (int64_t i = 0; i < N; i++) {
    ans ^= (f[i] * maskCode(i));
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t casesNum = 1;
  for (int64_t caseId = 1; caseId <= casesNum; caseId++) {
    solve();
  }
  return 0;
}
