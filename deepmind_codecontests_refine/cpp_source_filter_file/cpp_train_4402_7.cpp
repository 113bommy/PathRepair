#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> dp(31, vector<long long>(2, 0));
void calc(vector<long long> a, long long bit) {
  if (bit == 0) return;
  vector<long long> l, r, z;
  for (long long i = 0; i < a.size(); ++i) {
    if (a[i] & (1 << bit))
      r.push_back(a[i]), z.push_back(1);
    else
      l.push_back(a[i]), z.push_back(0);
  }
  long long c1 = 0, o1 = 0;
  for (long long i = 0; i < z.size(); ++i)
    if (z[i] == 1)
      ++o1;
    else
      c1 += o1;
  long long c2 = 0, o2 = 0;
  for (long long i = 0; i < z.size(); ++i)
    if (z[i] == 0)
      ++o2;
    else
      c2 += o2;
  dp[bit][0] += c1, dp[bit][1] += c2;
  if (l.size()) calc(l, bit - 1);
  if (r.size()) calc(r, bit - 1);
  return;
}
struct FenwickTree {
  vector<long long> bit;
  long long n;
  FenwickTree(long long n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<long long> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  long long sum(long long r) {
    long long ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long sum(long long l, long long r) { return sum(r) - sum(l - 1); }
  void add(long long idx, long long delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
long long getInvCount(vector<long long> a) {
  map<long long, vector<long long>> m;
  for (long long i = 0; i < a.size(); ++i) m[a[i]].push_back(i);
  long long z = 0;
  for (auto it : m) {
    ++z;
    for (auto j : it.second) a[j] = z;
  }
  long long mx = *max_element(a.begin(), a.end());
  FenwickTree f(mx + 1);
  long long c = 0;
  for (long long i = a.size() - 1; i >= 0; --i) {
    c += f.sum(a[i] - 1);
    f.add(a[i], 1);
  }
  return c;
}
signed main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  calc(a, 30);
  long long x = 0;
  for (long long i = 30; i >= 0; --i)
    if (dp[i][0] > dp[i][1]) x |= (1 << i);
  for (long long i = 0; i < n; ++i) a[i] = a[i] ^ x;
  long long ans = getInvCount(a);
  cout << ans << " " << x << "\n";
}
