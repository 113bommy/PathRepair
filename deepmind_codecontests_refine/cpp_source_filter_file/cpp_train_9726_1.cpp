#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10, maxm = 11;
int casn, n, m;
long long k;
struct node {
  int a, b, flag;
  bool operator<(const node &x) const {
    if (flag != x.flag) return flag < x.flag;
    if (a != x.a)
      return a < x.a;
    else
      return b > x.b;
  }
};
set<unsigned long long> ck;
map<unsigned long long, int> cnt;
map<unsigned long long, node> dp;
unsigned long long pw[40];
node dfs(unsigned long long now, int sum, int x, int len) {
  if (dp.count(now)) return dp[now];
  node mx = {0, 0, 0};
  for (int i = 0; i <= 25; ++i) {
    unsigned long long to = now * 27ull + i + 1;
    if (ck.count(to)) {
      node tmp = dfs(to, sum + i + 1, max(i + 1, x), len + 1);
      swap(tmp.a, tmp.b);
      tmp.flag ^= 1;
      tmp.a += (sum + i + 1) * max(i + 1, x) + cnt[to];
      if (mx < tmp) mx = tmp;
    }
    to = (i + 1) * pw[len] + now;
    if (ck.count(to)) {
      node tmp = dfs(to, sum + i + 1, max(i + 1, x), len + 1);
      swap(tmp.a, tmp.b);
      tmp.flag ^= 1;
      tmp.a += (sum + i + 1) * max(i + 1, x) + cnt[to];
      if (mx < tmp) mx = tmp;
    }
  }
  return dp[now] = mx;
}
int main() {
  cin >> n;
  pw[0] = 1;
  for (int i = 1; i <= 32; ++i) pw[i] = pw[i - 1] * 27;
  for (int i = 1; i <= n; ++i) {
    set<unsigned long long> vis;
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i <= len - 1; ++i) {
      unsigned long long t = 0;
      for (int j = i; j <= len - 1; ++j) {
        t = t * 27 + s[j] - 'a' + 1;
        ck.insert(t);
        if (!vis.count(t)) {
          ++cnt[t];
          vis.insert(t);
        }
      }
    }
  }
  auto ans = dfs(0, 0, 0, 0);
  if (ans.flag)
    cout << "first\n";
  else
    cout << "second\n";
  cout << ans.a << ' ' << ans.b << endl;
}
