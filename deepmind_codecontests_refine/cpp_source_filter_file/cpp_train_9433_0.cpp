#include <bits/stdc++.h>
using namespace std;
namespace str_hash {
const long long sd = 1e9 + 7, D = 1e9 + 9, N = 1e6 + 7;
long long b[N], B[N];
void init() {
  b[0] = 1;
  for (int i = (1); i <= (N - 1); ++i) b[i] = (b[i - 1] * 31) % sd;
  B[0] = 1;
  for (int i = (1); i <= (N - 1); ++i) B[i] = (B[i - 1] * 31) & ((1 << 30) - 1);
}
struct STR {
  int l;
  long long *h, *h2;
  void ins(char *s) {
    int len = strlen(s + 1);
    h = new long long[len + 1];
    h2 = new long long[len + 1];
    for (h[0] = 0, h2[0] = 0, l = 1; s[l]; l++) {
      h[l] = (h[l - 1] * 747 + s[l]) % sd;
      h2[l] = (h2[l - 1] * 747 + s[l]) & ((1 << 30) - 1);
    }
    l--;
  }
  pair<long long, long long> ask(int l, int r) {
    return pair<long long, long long>(
        (h[r] - h[l - 1] * b[r - l + 1] % sd + sd) % sd,
        (h2[r] - (h2[l - 1] * B[r - l + 1] & ((1 << 30) - 1)) +
         ((1 << 30) - 1)) &
            ((1 << 30) - 1));
  }
} str[N];
}  // namespace str_hash
using namespace str_hash;
int t, n;
char s[N];
vector<int> g[N];
set<pair<pair<long long, long long>, int> > st;
int dp[N][2], in[N], vis[N];
void dfs(int x) {
  dp[x][0] = 1, dp[x][1] = 0;
  for (auto &it : g[x]) {
    dfs(it);
    dp[x][0] += dp[it][1];
    dp[x][1] += max(dp[it][0], dp[it][1]);
  }
}
int main() {
  init(), scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = (1); i <= (n); ++i) {
      scanf("%s", s + 1);
      str[i].ins(s);
    }
    int idx = 0;
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (str[i].l); ++j) {
        ++idx;
        pair<long long, long long> now = str[i].ask(1, j);
        auto it = st.lower_bound(pair<pair<long long, long long>, int>(now, 0));
        if (it != st.end() && it->first == now)
          vis[idx] = 1;
        else
          st.insert(pair<pair<long long, long long>, int>(now, idx));
      }
    idx = 0;
    for (int i = (1); i <= (n); ++i)
      for (int j = (1); j <= (str[i].l); ++j) {
        ++idx;
        if (j == 1 || vis[idx]) continue;
        pair<long long, long long> now = str[i].ask(2, j);
        auto it = st.lower_bound(pair<pair<long long, long long>, int>(now, 0));
        if (it != st.end() && it->first == now) {
          g[it->second].push_back(idx);
          in[idx]++;
        }
      }
    int ans = 0;
    for (int i = (1); i <= (idx); ++i)
      if (in[i] == 0 && vis[i] == 0) {
        dfs(i), ans += max(dp[i][0], dp[i][1]);
      }
    printf("%d\n", ans);
    st.clear();
    for (int i = (1); i <= (idx); ++i)
      dp[i][0] = dp[i][1] = 0, g[i].clear(), vis[i] = in[i] = 0;
  }
  return 0;
}
