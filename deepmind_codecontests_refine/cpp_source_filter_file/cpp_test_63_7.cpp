#include <bits/stdc++.h>
using namespace std;
const long long N = 22;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
string s[N];
long long n, k;
long long num[N][400005];
long long ans[(1LL << N)][2];
long long pref[(1LL << N)], mn[N];
set<pair<long long, long long> > second;
set<long long> nums[400005];
void process() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '*' + s[i];
    second.clear();
    for (long long j = 0; j <= 400000; j++) nums[j].clear();
    long long prefix = 0;
    mn[i] = 0;
    for (long long j = 1; j < s[i].length(); j++) {
      prefix += (s[i][j] == '(' ? 1 : -1);
      mn[i] = min(mn[i], prefix);
      if (prefix <= 0) {
        second.insert({j, -prefix});
        nums[-prefix].insert(j);
      }
    }
    pref[(1LL << (i - 1))] = prefix;
    for (long long j = 400000; j >= 0; j--) {
      if (!nums[j].size()) continue;
      num[i][j] = nums[j].size();
      long long temp = (*nums[j].begin());
      set<pair<long long, long long> >::iterator it = second.find({j, temp}),
                                                 it2 = it;
      for (; it2 != second.end(); it2++)
        nums[(*it2).second].erase((*it2).first);
      second.erase(it, second.end());
    }
  }
  ans[0][1] = 0, ans[0][0] = -oo;
  for (long long i = 1; i < (1LL << n); i++) {
    ans[i][0] = ans[i][1] = -oo;
    if (__builtin_popcountll(i) >= 2) {
      for (long long j = 0; j < n; j++) {
        if (i & (1LL << j)) {
          pref[i] = (pref[i - (1LL << j)] + pref[(1LL << j)]);
          break;
        }
      }
    }
  }
  for (long long i = 1; i < (1LL << n); i++) {
    ans[i][0] = ans[i][1] = -oo;
    for (long long j = 0; j < n; j++) {
      if (!(i & (1LL << j))) continue;
      if (pref[i - (1LL << j)] + mn[j + 1] >= 0) {
        ans[i][1] = max(ans[i][1], ans[i - (1LL << j)][1] +
                                       num[j + 1][pref[i - (1LL << j)]]);
      } else
        ans[i][0] = max(ans[i][0], ans[i - (1LL << j)][1] +
                                       num[j + 1][pref[i - (1LL << j)]]);
      ans[i][0] = max(ans[i][0], ans[i - (1LL << j)][0]);
    }
  }
  cout << max(ans[(1LL << n) - 1][0], ans[(1LL << n) - 1][1]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  process();
}
