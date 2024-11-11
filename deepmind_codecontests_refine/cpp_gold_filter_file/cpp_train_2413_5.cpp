#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long pow1(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y >>= 1;
    x = (x * x) % mod;
  }
  return res;
}
bool comp(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
vector<long long> up;
vector<vector<long long> > dp;
vector<long long> minm;
vector<long long> maxm;
long long func(long long x, long long pos) {
  long long l = abs(minm[x] - pos) + dp[1][x];
  long long r = abs(maxm[x] - pos) + dp[0][x];
  return min(l, r) + (maxm[x] - minm[x]);
}
int main() {
  ios_base ::sync_with_stdio(false);
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  up.resize(q);
  dp.resize(2, vector<long long>(n + 1));
  minm.resize(n + 1, (long long)1e6);
  maxm.resize(n + 1, 0);
  for (int i = 0; i < k; i++) {
    long long a, b;
    cin >> a >> b;
    minm[a] = min(minm[a], b);
    maxm[a] = max(maxm[a], b);
  }
  while (maxm[n] == 0) n--;
  for (int i = 0; i < q; i++) cin >> up[i];
  sort(up.begin(), up.end());
  long long prev = n;
  int start = 1;
  while (maxm[start] == 0) start++;
  for (int i = n - 1; i >= start; i--) {
    if (maxm[i] == 0) continue;
    auto itr1 = --lower_bound(up.begin(), up.end(), minm[i]);
    auto itr2 = lower_bound(up.begin(), up.end(), minm[i]);
    auto itr3 = --lower_bound(up.begin(), up.end(), maxm[i]);
    auto itr4 = lower_bound(up.begin(), up.end(), maxm[i]);
    long long l1, r1, l2, r2;
    if (itr4 == up.end())
      r2 = up.back();
    else
      r2 = *itr4;
    l2 = *itr3;
    if (itr2 == up.end())
      r1 = up.back();
    else
      r1 = *itr2;
    l1 = *itr1;
    dp[0][i] = min(abs(r1 - minm[i]) + func(prev, r1),
                   abs(minm[i] - l1) + func(prev, l1));
    dp[1][i] = min(abs(r2 - maxm[i]) + func(prev, r2),
                   abs(maxm[i] - l2) + func(prev, l2));
    prev = i;
  }
  if (start == 1) {
    cout << func(1, 1) + n - 1;
  } else {
    long long l = up[0];
    cout << func(start, l) + (l - 1) + n - 1;
  }
}
