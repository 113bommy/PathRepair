#include <bits/stdc++.h>
using namespace std;
static void print(const unordered_map<int, pair<int, int>> &a) {
  for (auto &e : a) {
    cout << "id: " << e.first << " " << e.second.first << ", "
         << e.second.second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  unordered_map<int, pair<int, int>> s;
  s.reserve(m);
  for (int i = 0; i < m; ++i) {
    pair<int, int> temp;
    int a, b, c;
    cin >> a >> b >> c;
    if (s.count(a)) {
      s[a].first += c;
    } else {
      s[a] = {c, 0};
    }
    if (s.count(b)) {
      s[b].second += c;
    } else {
      s[b] = {0, c};
    }
  }
  uint64_t deb = 0;
  for (const auto &e : s) {
    auto v = e.second;
    if (v.first > v.second) {
      deb += v.first - v.second;
    }
  }
  cout << deb << endl;
  return 0;
}
