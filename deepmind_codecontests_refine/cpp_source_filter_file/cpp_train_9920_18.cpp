#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
struct Cnt {
  int cnt[200010], Cnt[200010], num;
  void init() {}
  inline void add(int x) {
    --Cnt[cnt[x]];
    if (++cnt[x] > num) ++num;
    ++Cnt[cnt[x]];
  }
  inline int Add(int x) { return max(num, cnt[x] + 1); }
  inline void del(int x) {
    if (--Cnt[cnt[x]] == 0 && cnt[x] == num) --num;
    --cnt[x];
    ++Cnt[cnt[x]];
  }
} _;
int cnt[200010];
const int offset = 200000;
int f[200010 * 2];
int ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int S = sqrt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
  int mx = 0, p;
  for (int i = 1; i <= n; ++i)
    if (cnt[i] > mx) mx = cnt[i], p = i;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] <= S || i == p) continue;
    memset(f, -1, sizeof f);
    f[offset] = 0;
    int s = 0;
    for (int j = 1; j <= n; ++j) {
      if (a[j] == p)
        --s;
      else if (a[j] == i)
        ++s;
      if (~f[s + offset])
        ans = max(ans, j - f[s + offset]);
      else
        f[s + offset] = j;
    }
  }
  for (int limit = 2; limit <= S; ++limit) {
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      while (j < n && _.Add(a[j + 1]) <= limit) _.add(a[++j]);
      if (_.Cnt[limit] >= 2) ans = max(ans, j - i + 1);
      _.del(a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
