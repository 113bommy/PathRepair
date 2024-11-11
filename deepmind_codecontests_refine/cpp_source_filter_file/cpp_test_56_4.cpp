#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
long long k, q;
set<long long> marked;
map<pair<int, int>, int> dp;
map<long long, int> color;
set<pair<int, int> > bad_edge = {{1, 1}, {2, 2}, {3, 3}, {4, 4},
                                 {5, 5}, {6, 6}, {1, 2}, {2, 1},
                                 {3, 4}, {4, 3}, {5, 6}, {6, 5}};
int add(int a, int b) { return (a + b) % M; }
int mul(int a, int b) { return (a * 1LL * b) % M; }
int fp(int b, long long p) {
  if (!p) return 1;
  int ret = fp(b, p / 2);
  ret = mul(ret, ret);
  if (p & 1) ret = mul(ret, b);
  return ret;
}
int get_color(string s) {
  if (s[0] == 'w') return 1;
  if (s[0] == 'y') return 2;
  if (s[0] == 'g') return 3;
  if (s[0] == 'b') return 4;
  if (s[0] == 'r') return 5;
  return 6;
}
int solve(long long node, int last) {
  if (!marked.count(node)) return 1;
  if (color.find(node) != color.end() && bad_edge.count({last, color[node]}))
    return 0;
  if (dp.find({node, last}) != dp.end()) return dp[{node, last}];
  int ret = 0;
  if (color.find(node) != color.end())
    ret = mul(solve(node * 2, color[node]), solve(node * 2 + 1, color[node]));
  else {
    for (int i = 1; i <= 6; ++i)
      if (!bad_edge.count({i, last}))
        ret = add(ret, mul(solve(node * 2, i), solve(node * 2 + 1, i)));
  }
  return dp[{node, last}] = ret;
}
void mark_path(long long x) {
  while (x) {
    marked.insert(x);
    x /= 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> q;
  while (q--) {
    long long x;
    string s;
    cin >> x >> s;
    color[x] = get_color(s);
    mark_path(x);
  }
  long long nodes_num = (1LL << k) - 1;
  cout << mul(solve(1, 0), fp(4, nodes_num - (long long)marked.size()));
  return 0;
}
