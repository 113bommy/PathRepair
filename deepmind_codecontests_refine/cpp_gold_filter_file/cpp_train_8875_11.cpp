#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
const long double EPS = 1e-22L;
int sgn(long double t) { return abs(t) < EPS ? 0 : (t > 0) - (t < 0); }
template <class S, int MS, int SIGMA>
struct AhoCorasick {
  int z;
  int dfa[MS + 1][SIGMA];
  bool out[MS + 1];
  using T = typename S::value_type;
  function<int(T)> ord;
  AhoCorasick(function<int(T)> ord) : z(1), ord(ord) {
    memset(dfa, -1, sizeof dfa);
    memset(out, false, sizeof out);
  }
  void insert(const S& s) {
    int cur = 0;
    for (T c : s) {
      int& nxt = dfa[cur][ord(c)];
      if (nxt == -1) nxt = z++;
      cur = nxt;
    }
    out[cur] = true;
  }
  void build() {
    queue<pair<int, int> > q;
    for (int lb = 0; lb < SIGMA; lb++) {
      int& nxt = dfa[0][lb];
      if (nxt == -1)
        nxt = 0;
      else
        q.emplace(nxt, 0);
    }
    while (!q.empty()) {
      auto [u, f] = q.front();
      q.pop();
      for (int lb = 0; lb < SIGMA; lb++) {
        int &v = dfa[u][lb], s = dfa[f][lb];
        if (v == -1) {
          v = s;
        } else {
          out[v] |= out[s];
          q.emplace(v, s);
        }
      }
    }
  }
};
int x;
vector<int> divisors;
vector<string> pats;
string pat;
void search(int mask, int sum) {
  if (sum == x) {
    pats.push_back(pat);
  } else {
    for (int i = 1; i <= 9; i++) {
      if (sum + i > x) continue;
      int aux = mask << i | 1 << 0;
      bool ok = true;
      for (int d : divisors) {
        if (aux & 1 << d) {
          ok = false;
          break;
        }
      }
      if (ok) {
        pat.push_back(i + '0');
        search(aux, sum + i);
        pat.pop_back();
      }
    }
  }
}
const int MS = 13739, N = 1000;
int dp[N + 1][MS];
int main() {
  string t;
  cin >> t;
  cin >> x;
  int m = t.length();
  for (int d = 1; d < x; d++) {
    if (x % d == 0) divisors.push_back(d);
  }
  search(1 << 0, 0);
  AhoCorasick<string, MS, 9> ac([](char c) { return c - '1'; });
  for (auto& s : pats) ac.insert(s);
  ac.build();
  for (int i = 0; i < m; i++) {
    for (int u = 0; u < ac.z; u++) {
      dp[i + 1][u] = max(dp[i + 1][u], dp[i][u]);
      int v = ac.dfa[u][ac.ord(t[i])];
      if (ac.out[v]) continue;
      dp[i + 1][v] = max(dp[i + 1][v], 1 + dp[i][u]);
    }
  }
  int ans = m - *max_element(dp[m], dp[m] + MS);
  cout << ans << '\n';
}
