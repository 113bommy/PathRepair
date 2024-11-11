#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 3;
const int maxm = 1e6 + 3;
const int mod = 1e9 + 7;
const int oo = 1e9 + 5;
const long double pi = 3.141592653589793238462643383279502884;
void input() {
  if (fopen("abc"
            ".inp",
            "r")) {
    freopen(
        "abc"
        ".inp",
        "r", stdin);
    freopen(
        "abc"
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct node {
  int c[26];
  node() { memset(c, -1, sizeof(c)); }
};
int n;
int a[maxn];
long long dp[maxn][2];
vector<node> trie;
vector<int> s[maxn * 30];
void ins(int id, int x) {
  int v = 0;
  for (int i = 30; i >= 0; --i) {
    int bit = (x >> i) & 1;
    if (trie[v].c[bit] == -1) {
      trie.push_back(node());
      trie[v].c[bit] = trie.size() - 1;
    }
    v = trie[v].c[bit];
    s[v].push_back(id);
  }
}
void get(int v, int bit) {
  if (bit < 0) return;
  int l = trie[v].c[0], r = trie[v].c[1];
  if (l != -1) get(l, bit - 1);
  if (r != -1) get(r, bit - 1);
  if (l == -1 || r == -1) return;
  int r_pos = 0, cur = 0;
  for (auto l_pos : s[l]) {
    while (r_pos < s[r].size() && s[r][r_pos] < l_pos) ++r_pos;
    cur += r_pos;
  }
  dp[bit][0] += cur;
  dp[bit][1] += 1ll * s[l].size() * s[r].size() - cur;
}
int main() {
  input();
  cin >> n;
  trie.push_back(node());
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ins(i, a[i]);
  }
  get(0, 30);
  long long inv = 0, ans = 0;
  for (int i = 0; i < 31; ++i) {
    inv += min(dp[i][0], dp[i][1]);
    if (dp[i][1] < dp[i][0]) ans |= (1 << i);
  }
  cout << inv << " " << ans;
  return 0;
}
