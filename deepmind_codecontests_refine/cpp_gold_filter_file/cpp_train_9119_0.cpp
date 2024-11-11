#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
constexpr int LG = 16;
constexpr int MOD = 1e9 + 7;
long long n;
vector<pair<int, int>> edges;
vector<set<int>> vec[N];
string s;
set<int> v;
int xa;
int isleaf[N];
vector<int> le;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int ptr = 0;
    bool c = false;
    int now = 0;
    s += ',';
    vec[i].push_back(v);
    for (auto j : s) {
      if (j == '-') {
        vec[i][ptr].insert(now);
        now = 0;
        ptr++;
        vec[i].push_back(v);
        c = false;
        continue;
      }
      if (j == ':') {
        c = true;
        continue;
      }
      if (j == ',') {
        vec[i][ptr].insert(now);
        now = 0;
        continue;
      }
      if (c) {
        now *= 10;
        now += j - '0';
      }
    }
    if (ptr == 0) le.push_back(i), isleaf[i] = 1, xa++;
  }
  for (int i = 1; (int)le.size() > 1; i++) {
    if (xa == n) {
      edges.push_back({le[0], le[1]});
    }
    for (auto j : le) {
      for (int k = 1; k <= n; k++) {
        if (isleaf[k]) continue;
        for (auto &za : vec[k]) {
          if ((int)za.size() == 0) continue;
          if ((int)za.size() == 1 && *za.begin() == j) {
            za.clear();
            edges.push_back({j, k});
            break;
          }
        }
      }
    }
    for (auto j : le) {
      for (int k = 1; k <= n; k++) {
        if (isleaf[k]) continue;
        for (auto &za : vec[k]) {
          if (za.count(j) == 1) {
            za.erase(j);
            break;
          }
        }
      }
    }
    le.clear();
    for (int j = 1; j <= n; j++) {
      if (!isleaf[j]) {
        int cnt = 0;
        for (auto &k : vec[j]) {
          if ((int)k.size()) cnt++;
          if (cnt > 1) break;
        }
        if (cnt == 1) {
          isleaf[j] = 1;
          xa++;
          le.push_back(j);
        }
      }
    }
  }
  if ((int)edges.size() != n - 1) {
    cout << -1 << '\n';
    return 0;
  }
  cout << n - 1 << '\n';
  for (auto i : edges) cout << i.first << ' ' << i.second << '\n';
  return 0;
}
