#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e6 + 10;
using ll = long long;
int N, M, K, T;
ll f[MAXN][10];
struct Rounds {
  vector<pair<int, int>> cards;
} rnds[MAXN];
void Extract(int r, vector<vector<int>>& v) {
  multiset<int> s[4];
  for (auto& p : rnds[r].cards) {
    s[p.first].emplace(p.second);
  }
  int t = 0;
  if (!s[1].empty()) t = max(t, *s[1].rbegin());
  if (!s[2].empty()) t = max(t, *s[2].rbegin());
  if (!s[3].empty()) t = max(t, *s[3].rbegin());
  v[1].emplace_back(t);
  if (!s[1].empty()) {
    if (s[1].size() >= 2) {
      int a = *(++s[1].rbegin()), b = *s[1].rbegin();
      if (!s[2].empty()) {
        int c = *s[2].rbegin();
        if (c > a) {
          v[2].emplace_back(min(b, c));
          v[2].emplace_back(max(b, c));
        } else {
          v[2].emplace_back(a);
          v[2].emplace_back(b);
        }
      } else {
        v[2].emplace_back(a);
        v[2].emplace_back(b);
      }
    } else {
      if (!s[2].empty()) {
        int a = *s[1].rbegin(), b = *s[2].rbegin();
        v[2].emplace_back(min(a, b));
        v[2].emplace_back(max(a, b));
      }
    }
  }
  if (s[1].size() >= 3) {
    auto it = s[1].rbegin();
    int c = *it++;
    int b = *it++;
    int a = *it++;
    v[3].emplace_back(a);
    v[3].emplace_back(b);
    v[3].emplace_back(c);
  }
}
ll Solution() {
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (int i = (int)0; i < (int)N; ++i) {
    memcpy(f[i + 1], f[i], sizeof(f[i]));
    vector<vector<int>> choices(4);
    Extract(i, choices);
    for (int j = (int)0; j < (int)10; ++j) {
      if (f[i][j] == -1) continue;
      for (int k = (int)1; k < (int)4; ++k) {
        if (!choices[k].empty()) {
          ll g = accumulate(choices[k].begin(), choices[k].end(), 0LL);
          int t = j + k;
          if (t >= 10) {
            t %= 10;
            g += choices[k].back();
          }
          f[i + 1][t] = max(f[i + 1][t], f[i][j] + g);
        }
      }
    }
  }
  ll ans = *max_element(f[N], f[N] + 10);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N) {
    int c, d;
    for (int i = (int)0; i < (int)N; ++i) {
      cin >> M;
      for (int j = (int)0; j < (int)M; ++j) {
        cin >> c >> d;
        rnds[i].cards.emplace_back(c, d);
      }
    }
    cout << Solution() << '\n';
  }
  return 0;
}
