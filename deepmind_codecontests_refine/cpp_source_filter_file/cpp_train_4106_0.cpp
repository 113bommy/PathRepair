#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using row = vector<int>;
using ii = pair<int, int>;
const int N = 5e5 + 5, M = 1e6 + 5, A = 6561, LG = 17, MOD = 1e9 + 7;
const int BLOCK = 1900;
const int BLOCKN = N / BLOCK + 1;
const long double EPS = 1e-7;
vector<int> g[2];
map<int, int> cnt[2];
int n, m, s, f;
int count(bool f, int l, int r) {
  return upper_bound(g[f].begin(), g[f].end(), r) -
         lower_bound(g[f].begin(), g[f].end(), l);
}
pair<int, ll> ans;
void addToMax(int val, ll cnt) {
  if (!cnt) return;
  if (ans.first < val) ans = make_pair(val, 0);
  if (ans.first == val) ans.second += cnt;
}
void solveMax(bool k) {
  if (g[k].empty()) return;
  if (g[k].size() >= 3) {
    int cntL = cnt[k][g[k][0]];
    int cntR = cnt[k][g[k][1]];
    int cntM = g[k].size() - cntL - cntR;
    int val = (g[k].back() - g[k][0]) * 2;
    ll sum = 0;
    if (g[k][0] == g[k].back()) {
      addToMax(val, 1ll * cntL * (cntL - 1) * (cntL - 2) / 6);
    } else {
      sum += 1ll * cntL * cntM * cntR;
      sum += 1ll * cntL * (cntL - 1) / 2 * cntR;
      sum += 1ll * cntR * cntR * (cntR - 1) / 2;
      addToMax(val, sum);
    }
  }
  for (auto x : g[k]) {
    {
      int L = count(k ^ 1, 1, x);
      int R = count(k ^ 1, x, n);
      int val = cnt[k ^ 1][x];
      addToMax(2 * n,
               1ll * L * R - 1ll * val * val + 1ll * val * (val - 1) / 2);
    }
    {
      int idx =
          upper_bound(g[k ^ 1].begin(), g[k ^ 1].end(), x) - g[k ^ 1].begin();
      if (idx != g[k ^ 1].size()) {
        addToMax(2 * (n + x - g[k ^ 1][idx]),
                 1ll * cnt[k ^ 1][g[k ^ 1][idx]] *
                     count(k ^ 1, g[k ^ 1][idx] + 1, n));
        addToMax(2 * (n + x - g[k ^ 1][idx]),
                 1ll * cnt[k ^ 1][g[k ^ 1][idx]] *
                     (cnt[k ^ 1][g[k ^ 1][idx]] - 1) / 2);
      }
    }
    {
      int idx =
          lower_bound(g[k ^ 1].begin(), g[k ^ 1].end(), x) - g[k ^ 1].begin();
      --idx;
      if (~idx) {
        addToMax(2 * (n + g[k ^ 1][idx] - x),
                 1ll * cnt[k ^ 1][g[k ^ 1][idx]] *
                     count(k ^ 1, 1, g[k ^ 1][idx] - 1));
        addToMax(2 * (n - x + g[k ^ 1][idx]),
                 1ll * cnt[k ^ 1][g[k ^ 1][idx]] *
                     (cnt[k ^ 1][g[k ^ 1][idx]] - 1) / 2);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> s >> f;
    g[s].push_back(f);
    cnt[s][f]++;
  }
  sort(g[0].begin(), g[0].end());
  sort(g[1].begin(), g[1].end());
  solveMax(0);
  solveMax(1);
  cerr << ans.first << '\n';
  cout << ans.second << '\n';
  return 0;
}
