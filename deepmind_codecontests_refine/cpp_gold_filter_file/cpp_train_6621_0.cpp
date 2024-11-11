#include <bits/stdc++.h>
using namespace std;
const int size = 100000 + 11;
int n;
string t[size];
int k[size];
vector<int> x[size];
bool input() {
  if (cin >> n) {
    for (int i = 0; i < (n); ++i) {
      cin >> t[i] >> k[i];
      x[i] = vector<int>(k[i]);
      for (int j = 0; j < (k[i]); ++j) cin >> x[i][j];
    }
    return true;
  }
  return false;
}
struct node_t {
  int id;
  int pos;
  int len;
};
bool operator<(const node_t& l, const node_t& r) {
  return l.pos == r.pos ? l.len > r.len : l.pos < r.pos;
}
vector<node_t> nodes;
const int res_size = 2000000 + 11;
char res[res_size];
int resn;
int build() {
  int len = 0;
  nodes.clear();
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (k[i]); ++j) {
      nodes.push_back(node_t{i, x[i][j] - 1, (int)t[i].size()});
      len = max(len, x[i][j] + (int)t[i].size() - 1);
    }
  sort(begin(nodes), end(nodes));
  return len;
}
void solve() {
  fill(res, res + res_size, 'a');
  resn = build();
  int len = 0;
  for (const auto& node : nodes) {
    if (node.pos > len) len = node.pos;
    if (node.pos + node.len - 1 < len) continue;
    const auto& sub = t[node.id];
    int offset = len - node.pos;
    copy(sub.c_str() + offset, sub.c_str() + sub.size(), res + len);
    len = node.pos + node.len - 1;
  }
}
void output() {
  for (int i = 0; i < (resn); ++i) cout << res[i];
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (input()) {
    solve();
    output();
  }
  return 0;
}
