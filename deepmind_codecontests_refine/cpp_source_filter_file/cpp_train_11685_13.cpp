#include <bits/stdc++.h>
using namespace std;
void dbg() { std::cout << "  #\n"; }
template <typename T, typename... Args>
void dbg(T a, Args... args) {
  std::cout << a << ' ';
  dbg(args...);
}
const int maxn = 1e6 + 10;
const int MAX = 1000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m;
vector<int> a[maxn];
vector<pair<int, int> > ans;
int ru[maxn];
int maxx;
void dfs(int now, int fa, int pastpoint) {
  int remain = a[now].size();
  int nextpoint = pastpoint;
  for (auto to : a[now])
    if (to != fa) {
      if (nextpoint == maxx) {
        nextpoint = pastpoint - remain - 1;
        ans.push_back(make_pair(now, nextpoint));
      }
      remain--;
      nextpoint++;
      ans.push_back(make_pair(to, nextpoint));
      dfs(to, now, nextpoint);
    }
  if (nextpoint + 1 != pastpoint) {
    ans.push_back(make_pair(now, pastpoint - 1));
    nextpoint = pastpoint - 1;
  }
  if (now != 1) ans.push_back(make_pair(fa, nextpoint + 1));
}
void solve() {
  cin >> n;
  for (int i = (1); i <= (n - 1); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
    ru[x]++;
    ru[y]++;
  }
  maxx = *max_element(ru + 1, ru + 1 + n);
  ans.push_back(make_pair(1, 0));
  dfs(1, -1, 0);
  int len = ans.size() - 1;
  printf("%d\n", len);
  for (int i = (0); i <= (len - 1); ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}
signed main() {
  int T = 1;
  while (T--) {
    solve();
  }
}
