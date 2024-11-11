#include <bits/stdc++.h>
using namespace std;
void print() {
  if constexpr (0) cout << '\n';
}
template <typename T, typename... Ts>
void print(const T& value, const Ts&... values) {
  if constexpr (0) cout << value << ' ', print(values...);
}
const long long N = 3e5 + 5;
long long n, s[3];
long long a[N];
long long grundy[N][3];
long long Mex(vector<long long> val) {
  long long ret = 0;
  sort(val.begin(), val.end());
  val.resize(distance(val.begin(), unique(val.begin(), val.end())));
  if (val.empty()) return ret = 0;
  long long pre = -1;
  for (auto it : val) {
    if (it != pre + 1) return ret = pre + 1;
    pre = it;
  }
  return ret = pre + 1;
}
pair<long long, long long> prep() {
  map<vector<long long>, long long> mark;
  for (long long lev = 1;; lev++) {
    grundy[lev][0] =
        Mex({grundy[max(0LL, lev - s[1])][1], grundy[max(0LL, lev - s[2])][2]});
    grundy[lev][1] =
        Mex({grundy[max(0LL, lev - s[0])][0], grundy[max(0LL, lev - s[2])][2]});
    grundy[lev][2] =
        Mex({grundy[max(0LL, lev - s[0])][0], grundy[max(0LL, lev - s[1])][1],
             grundy[max(0LL, lev - s[2])][2]});
    if (lev >= 4) {
      vector<long long> cur;
      for (long long i = (long long)lev - 4; i <= (long long)lev; i++)
        for (long long j = (long long)0; j <= (long long)2; j++)
          cur.push_back(grundy[i][j]);
      if (mark.find(cur) == mark.end())
        mark[cur] = lev - 4;
      else {
        return {lev - 4, lev - 4 - mark[cur]};
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cin >> n >> s[2] >> s[0] >> s[1];
    for (long long i = (long long)0; i <= (long long)n - 1; i++) cin >> a[i];
    long long sta, len;
    tie(sta, len) = prep();
    auto getg = [&](long long val, long long type) {
      if (val >= sta)
        return grundy[sta + (val - sta) % len][type];
      else
        return grundy[val][type];
    };
    long long ans = 0;
    long long out = 0;
    for (long long i = (long long)0; i <= (long long)n - 1; i++)
      out ^= getg(a[i], 2);
    for (long long i = (long long)0; i <= (long long)n - 1; i++) {
      out ^= getg(a[i], 2);
      for (long long j = (long long)0; j <= (long long)2; j++) {
        long long nx = max(0LL, a[i] - s[j]);
        long long cur = (out ^ getg(nx, j));
        if (cur == 0) ans++;
      }
      out ^= getg(a[i], 2);
    }
    cout << ans << '\n';
  }
}
