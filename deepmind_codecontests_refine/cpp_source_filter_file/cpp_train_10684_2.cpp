#include <bits/stdc++.h>
using std::bitset;
using std::cerr;
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::fixed;
using std::ios_base;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::nth_element;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int n;
unordered_map<string, int> w, h, tp, border, spacing;
unordered_map<string, vector<string>> g;
unordered_set<string> used;
set<string> names;
void dfs(string s) {
  used.insert(s);
  if (tp[s] == 0) return;
  for (auto& x : g[s]) {
    if (used.find(x) == used.end()) dfs(x);
  }
  if (g[s].empty()) return;
  if (tp[s] == 1) {
    h[s] += (g[s].size() - 1) * spacing[s];
  } else {
    w[s] += (g[s].size() - 1) * spacing[s];
  }
  for (auto& x : g[s]) {
    if (tp[s] == 1) {
      h[s] += h[x];
      w[s] = std::max(w[s], w[x]);
    } else {
      w[s] += w[x];
      h[s] = std::max(h[s], h[x]);
    }
  }
  w[s] += 2 * border[s];
  h[s] += 2 * border[s];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  string s;
  getline(cin, s);
  n = std::stoi(s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    if (s[0] == 'W') {
      int j = std::find(s.begin(), s.end(), ' ') - s.begin();
      int k = std::find(s.begin(), s.end(), '(') - s.begin();
      int l = std::find(s.begin(), s.end(), ',') - s.begin();
      int m = std::find(s.begin(), s.end(), ')') - s.begin();
      string name = s.substr(j + 1, k - j - 1);
      int ww = std::stoi(s.substr(k + 1, l - k - 1));
      int hh = std::stoi(s.substr(l + 1, m - l - 1));
      names.insert(name);
      w[name] = ww;
      h[name] = hh;
      tp[name] = 0;
      border[name] = 0;
      spacing[name] = 0;
      if (g.find(name) == g.end()) g[name] = vector<string>();
    } else if (s[0] == 'V') {
      int j = std::find(s.begin(), s.end(), ' ') - s.begin();
      string name = s.substr(j + 1, s.size() - j - 1);
      names.insert(name);
      w[name] = 0;
      h[name] = 0;
      tp[name] = 1;
      border[name] = 0;
      spacing[name] = 0;
      if (g.find(name) == g.end()) g[name] = vector<string>();
    } else if (s[0] == 'H') {
      int j = std::find(s.begin(), s.end(), ' ') - s.begin();
      string name = s.substr(j + 1, s.size() - j - 1);
      names.insert(name);
      w[name] = 0;
      h[name] = 0;
      tp[name] = 2;
      border[name] = 0;
      spacing[name] = 0;
      if (g.find(name) == g.end()) g[name] = vector<string>();
    } else {
      int j = std::find(s.begin(), s.end(), '.') - s.begin();
      int k = std::find(s.begin(), s.end(), '(') - s.begin();
      int l = std::find(s.begin(), s.end(), ')') - s.begin();
      string name = s.substr(0, j);
      string op = s.substr(j + 1, k - j - 1);
      string param = s.substr(k + 1, l - k - 1);
      if (op == "pack") {
        g[name].push_back(param);
      } else if (op == "set_border") {
        border[name] = std::stoi(param);
      } else {
        spacing[name] = std::stoi(param);
      }
    }
  }
  for (auto& s : names) {
    if (used.find(s) == used.end()) {
      dfs(s);
    }
  }
  for (auto& s : names) {
    cout << s << ' ' << w[s] << ' ' << h[s] << '\n';
  }
  return 0;
}
