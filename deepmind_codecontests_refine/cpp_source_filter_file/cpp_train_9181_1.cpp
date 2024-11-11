#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
long long LG = 18;
vector<vector<long long>> mx;
long long GL[300000];
long long gmx(long long l, long long r) {
  long long k = GL[r - l + 1];
  return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  ;
  for (int q = 2; q < 300000; q++)
    GL[q] = (2 << GL[q - 1]) > q ? GL[q - 1] : GL[q - 1] + 1;
  long long z;
  cin >> z;
  for (; z; z--) {
    long long a;
    cin >> a;
    vector<long long> m(a), dp(a), last(a + 1);
    mx = vector<vector<long long>>(LG, vector<long long>(a));
    long long MMXX = 0;
    for (int q = 0; q < a; q++)
      cin >> m[q], mx[0][q] = m[q], MMXX = max(MMXX, m[q]);
    for (int q = 1; q < LG; q++)
      for (int w = 0; w + (1 << q) <= a; w++)
        mx[q][w] = max(mx[q - 1][w], mx[q - 1][w + (1 << q)]);
    long long k;
    cin >> k;
    vector<pair<long long, long long>> n(k);
    long long mxs = 0;
    for (int q = 0; q < k; q++)
      cin >> n[q].first >> n[q].second, mxs = max(n[q].first, mxs);
    if (MMXX > mxs) {
      cout << "-1\n";
      continue;
    }
    sort(n.begin(), n.end(),
         [](pair<long long, long long> &p1, pair<long long, long long> &p2) {
           return p1.second != p2.second ? p1.second < p2.second
                                         : p1.first > p2.first;
         });
    long long cur_max = 0;
    map<long long, long long> mp;
    for (int q = k - 1; q >= 0; q--) {
      cur_max = max(cur_max, n[q].first);
      mp[n[q].second] = cur_max;
    }
    last[0] = a;
    long long cur = 0;
    for (int q = a - 1; q >= 0; q--) {
      long long p = last[cur], mxv = gmx(q, p - 1), len = p - q;
      auto it = mp.lower_bound(len);
      if (it == mp.end() || (*it).second < mxv) {
        cur++, q++;
        continue;
      }
      dp[q] = cur + 1;
      last[cur + 1] = q;
    }
    cout << dp[0] << "\n";
  }
}
