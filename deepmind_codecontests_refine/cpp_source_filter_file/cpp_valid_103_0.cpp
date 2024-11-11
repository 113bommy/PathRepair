#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void dout(string name, int idx, T arg) {
  cerr << name << " = " << to_string(arg);
}
template <typename T1, typename... T2>
void dout(string names, int idx, T1 arg, T2... args) {
  cerr << names.substr(0, names.find(',')) << " = " << to_string(arg) << ", ";
  dout(names.substr(names.find(',') + 2), idx + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, z;
  cin >> n >> m >> z;
  vector<vector<int>> g(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x][y] = 1;
    g[y][x] = 1;
  }
  vector<int> match(n, -1);
  int ans = 0;
  set<vector<int>> matches;
  function<void()> DP = [&]() {
    assert(*min_element(match.begin(), match.end()) > -1);
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
      if (i < match[i]) {
        pairs.emplace_back(i, match[i]);
      }
    }
    assert((int)2 * pairs.size() == n);
    vector<vector<vector<int>>> dp(
        1 << (n / 2), vector<vector<int>>(n / 2, vector<int>(2, 0)));
    for (int i = 0; i < (int)pairs.size(); i++) {
      int x = pairs[i].first, y = pairs[i].second;
      if (g[x][y]) {
        assert(g[y][x]);
        dp[1 << i][i][0] = dp[1 << i][i][1] = 1;
      }
    }
    for (int mask = 1; mask < (1 << (int)pairs.size()); mask++) {
      for (int i = 0; i < (int)pairs.size(); i++) {
        int xi = pairs[i].first, yi = pairs[i].second;
        if (mask & (1 << i)) {
          for (int j = 0; j < (int)pairs.size(); j++) {
            if (mask & (1 << j)) {
              int xj = pairs[j].first, yj = pairs[j].second;
              if (g[xi][xj] && g[yi][yj]) {
                dp[mask][i][0] |= dp[mask ^ (1 << i)][j][0];
              }
              if (g[xi][yj] && g[xj][yi]) {
                dp[mask][i][0] |= dp[mask ^ (1 << i)][j][1];
              }
              if (g[yi][xj] && g[yj][xi]) {
                dp[mask][i][1] |= dp[mask ^ (1 << i)][j][0];
              }
              if (g[yi][yj] && g[xi][xj]) {
                dp[mask][i][1] |= dp[mask ^ (1 << i)][j][1];
              }
            }
          }
        }
      }
    }
    int p = 1;
    for (int i = 0; i < n / 2; i++) {
      p *= z;
    }
    int any = 0;
    for (int i = 0; i < (int)pairs.size(); i++) {
      for (int j = 0; j < 2; j++) {
        any |= dp[(1 << ((int)pairs.size())) - 1][i][j];
      }
    }
    if (any) {
      matches.insert(match);
    }
  };
  function<void(int)> DoMatch = [&](int i) {
    if (i == n) {
      DP();
      return;
    }
    if (match[i] != -1) {
      DoMatch(i + 1);
    } else {
      for (int j = i + 1; j < n; j++) {
        if (match[j] == -1) {
          match[i] = j;
          match[j] = i;
          DoMatch(i + 1);
          match[i] = -1;
          match[j] = -1;
        }
      }
    }
  };
  vector<int> color(n, -1);
  vector<vector<int>> comp(6);
  set<vector<int>> cached;
  vector<int> new_match(n);
  vector<int> f(n + 1);
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * (z - i + 1);
  }
  function<bool(int)> Calculate = [&](int i) {
    if (i == n) {
      if (matches.count(new_match)) {
        int size = 1 + *max_element(color.begin(), color.end());
        ans += f[size];
        return true;
      }
      return false;
    }
    if (new_match[i] != -1) {
      return Calculate(i + 1);
    }
    for (int j : comp[color[i]]) {
      if (i == j || new_match[j] != -1) {
        continue;
      }
      new_match[i] = j;
      new_match[j] = i;
      if (Calculate(i + 1)) {
        return true;
      }
      new_match[i] = -1;
      new_match[j] = -1;
    }
    return false;
  };
  function<void(int, int)> DoColoring = [&](int i, int size) {
    if (i == n) {
      bool ok = true;
      for (int j = 0; j < 6; j++) {
        if ((int)comp[j].size() % 2) {
          ok = false;
          break;
        }
      }
      if (ok) {
        new_match = vector<int>(n, -1);
        Calculate(0);
      }
      return;
    }
    for (int j = 0; j < size; j++) {
      color[i] = j;
      comp[j].push_back(i);
      DoColoring(i + 1, min(6, max(size, color[i] + 2)));
      comp[j].pop_back();
      color[i] = -1;
    }
  };
  DoMatch(0);
  DoColoring(0, 1);
  cout << ans << '\n';
  return 0;
}
