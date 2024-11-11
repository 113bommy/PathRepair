#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int M = 1e3 + 5;
const int Mod = 998244353;
struct Base {
  int m;
  vector<long long> A;
  Base(int m = 0) : m(m) { A.assign(max(m, 1), 0); }
  void insert(long long x) {
    for (long long i = m - 1; ~i; --i) {
      if (x & (1LL << i)) {
        if (A[i]) {
          x ^= A[i];
        } else {
          A[i] = x;
          break;
        }
      }
    }
  }
  vector<long long> Get() {
    vector<long long> Res;
    for (int i = 0; i < m; i++)
      if (A[i]) Res.push_back(A[i]);
    return Res;
  }
};
vector<long long> v;
int k;
int dp[16][16][1 << 16 | 5];
int CNT(long long x) {
  int cnt = 0;
  while (x) cnt += x & 1, x >>= 1;
  return cnt;
}
int Try(int i, int j, int XOR) {
  if (i == k) return CNT(XOR) == j;
  int& ret = dp[i][j][XOR];
  if (~ret) return ret;
  return ret = (Try(i + 1, j, XOR) + Try(i + 1, j, XOR ^ v[i])) % Mod;
}
long long fp(long long x, long long y, long long m = Mod) {
  long long res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i) res = res * x % m;
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << fp(2, n) << endl;
    return 0;
  }
  m++;
  Base b(m);
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    b.insert(x);
  }
  int mid = min(15, m);
  for (int i = 0; i < mid; i++)
    if (b.A[i]) v.push_back(b.A[i]);
  vector<long long> v2;
  for (int i = mid; i < m; i++)
    if (b.A[i]) v2.push_back(b.A[i]);
  k = v.size();
  int k2 = v2.size();
  memset(dp, -1, sizeof(dp));
  vector<long long> ans(m + 1);
  for (int i = 0; i < (1 << k2); i++) {
    long long XOR = 0;
    for (int j = 0; j < k2; j++)
      if (i & (1 << j)) XOR ^= v2[j];
    int cnt = CNT(XOR >> mid);
    XOR &= (1 << mid) - 1;
    for (int j = 0; cnt + j <= m && j <= mid; j++)
      ans[j + cnt] += Try(0, j, XOR);
  }
  ans.pop_back();
  for (auto i : ans) cout << i % Mod * fp(2, n - (k + k2)) % Mod << ' ';
  cout << '\n';
  return 0;
}
