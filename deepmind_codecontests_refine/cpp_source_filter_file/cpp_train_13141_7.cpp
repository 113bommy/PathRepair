#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int dx8[] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[] = {0, -1, 0, 1, 1, -1, 1, -1};
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long ceil1(long long a, long long b) { return (a + b - 1) / b; }
vector<vector<long long>> sum, occ;
vector<vector<long long>> occurence;
vector<long long> neg, neg_ind;
long long get(long long val, long long ind) {
  if (occurence[val].size() == 0) return -1;
  auto i = lower_bound(occurence[val].begin(), occurence[val].end(), ind) -
           occurence[val].begin();
  i--;
  if (i < 0) return -1;
  return occurence[val][i];
}
long long geti(long long val, long long ind) {
  if (occ[val].size() == 0) return -1;
  auto i =
      lower_bound(occ[val].begin(), occ[val].end(), ind) - occ[val].begin();
  i--;
  if (i < 0) return -1;
  return i;
}
long long gets(long long ind, long long val) {
  auto i = geti(val, ind);
  if (i == -1) return 0;
  return sum[val][i];
}
void dbg() {
  long long x;
  x = 5;
}
long long getn(long long l, long long r) {
  if (int(neg.size()) == 0) return 0;
  if (l > r) return 0;
  auto i2 = upper_bound(neg_ind.begin(), neg_ind.end(), r) - neg_ind.begin();
  i2--;
  if (i2 < 0) return 0;
  long long ans = neg[i2];
  auto i1 = lower_bound(neg_ind.begin(), neg_ind.end(), l) - neg_ind.begin();
  i1--;
  if (i1 >= 0) ans -= neg[i1];
  return ans;
}
void solve() {
  long long n, m;
  cin >> n;
  n += 2;
  vector<long long> a(n);
  vector<long long> ct(n);
  for (long long i = 1; i < n - 1; i++) cin >> a[i];
  for (long long i = 1; i < n - 1; i++) cin >> ct[i];
  a[n - 1] = n + 1;
  cin >> m;
  m += 2;
  vector<long long> b(m);
  for (long long i = 1; i < m - 1; i++) cin >> b[i];
  b[m - 1] = n + 1;
  for (long long i = 0; i < n; i++) {
    auto ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (ind == m) {
      a[i] = 2 * m - 1;
      continue;
    }
    if (a[i] == b[ind])
      a[i] = 2 * ind;
    else
      a[i] = 2 * ind - 1;
  }
  occ = vector<vector<long long>>(3 * n);
  sum = vector<vector<long long>>(3 * n);
  neg.clear();
  neg_ind.clear();
  occurence = vector<vector<long long>>(3 * n);
  vector<vector<long long>>& debocc = occurence;
  vector<vector<long long>>& debsum = sum;
  vector<long long>& deneg = neg;
  vector<long long>& deneg_ind = neg_ind;
  for (long long i = 0; i < n; i++) {
    occurence[a[i]].push_back(i);
    if (ct[i] < 0) {
      neg_ind.push_back(i);
      long long x = 0;
      if (int(neg.size()) > 0) x = neg.back();
      neg.push_back(x + ct[i]);
    } else {
      occ[a[i]].push_back(i);
      long long x = 0;
      if (int(sum[a[i]].size()) > 0) x = sum[a[i]].back();
      sum[a[i]].push_back(x + ct[i]);
    }
  }
  vector<long long> dp(n, 1e18);
  dp[0] = 0;
  for (long long i = 1; i < n; i++) {
    long long x = i;
    if (a[i] % 2 == 0) {
      auto jx = get(a[i] - 2, i);
      long long y = getn(jx + 1, i - 1);
      if (jx != -1) {
        dp[x] = min(dp[x], dp[jx] + gets(i, a[i]) + gets(i, a[i] - 1) +
                               getn(jx + 1, i - 1));
      }
      auto px = get(a[i], i);
      if (px != -1) {
        dp[x] = min(dp[x], dp[px] + getn(px + 1, x));
      }
      dbg();
    }
  }
  long long last = 2 * m - 2;
  auto ans = dp[occ[last].back()];
  if (ans == 1e18)
    cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';
    cout << dp[occ[last].back()] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
