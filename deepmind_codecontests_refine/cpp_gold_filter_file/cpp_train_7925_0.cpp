#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
long long cd;
char s[maxn], t[maxn];
long long n, a[maxn], b[maxn], f[maxn], pre, res, cnt, c[maxn];
vector<pair<long long, long long>> ans;
void dfs(long long x, long long op) {
  if (cnt > 1e5 + 5) return;
  if (op == 1) {
    if (a[x + 1] == 9) dfs(x + 1, -1);
    a[x]++, a[x + 1]++;
    ans.push_back({x, 1});
    cnt++;
  } else {
    if (a[x + 1] == 0) dfs(x + 1, 1);
    a[x]--, a[x + 1]--;
    ans.push_back({x, -1});
    cnt++;
  }
}
signed main() {
  cin >> n;
  scanf("%s%s", s + 1, t + 1);
  for (long long i = 1; i <= n; i++) a[i] = s[i] - '0', c[i] = a[i];
  for (long long i = 1; i <= n; i++) b[i] = t[i] - '0';
  for (long long i = 1; i <= n; i++) {
    res += abs(b[i] - pre - a[i]);
    pre = b[i] - pre - a[i];
  }
  if (pre != 0) {
    puts("-1");
    return 0;
  }
  cout << res << endl;
  for (long long i = 1; i < n && cnt <= 1e5 + 5; i++) {
    for (; a[i] > b[i] && cnt <= 1e5 + 5; cnt++) {
      if (a[i + 1] == 0) dfs(i + 1, 1);
      a[i]--, a[i + 1]--;
      ans.push_back(make_pair(i, -1));
    }
    for (; a[i] < b[i] && cnt <= 1e5 + 5; cnt++) {
      if (a[i + 1] == 9) dfs(i + 1, -1);
      a[i]++, a[i + 1]++;
      ans.push_back(make_pair(i, 1));
    }
  }
  long long cnt = 0;
  for (auto v : ans) {
    printf("%lld %lld\n", v.first, v.second);
    cnt++;
    if (cnt == 1e5) return 0;
  }
}
