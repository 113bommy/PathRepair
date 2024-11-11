#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& t) {
  for (int i = 0; i < t.size(); i++) in >> t[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& t) {
  for (int i = 0; i < t.size(); i++) out << t[i] << " ";
  return out;
}
vector<int> ans;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
struct Node {
  bool us = 0;
  int val, h;
  vector<int> to;
};
vector<Node> g;
void dfs1(int v, int p = -1, int h = 0) {
  g[v].h = h;
  g[v].us = 1;
  for (int to : g[v].to) {
    if (g[to].us) continue;
    ans[to] = gcd(g[v].val, ans[v]);
    dfs1(to, v, h + 1);
  }
}
map<int, int> w;
void dfs2(int v) {
  g[v].us = 1;
  for (auto& i : w) {
    if (g[v].val % i.first == 0) i.second++;
    if (i.second >= g[v].h) ans[v] = max(ans[v], i.first);
  }
  for (int to : g[v].to) {
    if (g[to].us) continue;
    dfs2(to);
  }
  for (auto& i : w) {
    if (g[v].val % i.first == 0) i.second--;
  }
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  ans.resize(n);
  for (int i = 0; i < n; i++) cin >> g[i].val;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].to.push_back(b);
    g[b].to.push_back(b);
  }
  dfs1(0);
  for (int i = 0; i < n; i++) g[i].us = 0;
  for (int i = 1; i * i <= g[0].val; i++) {
    if (g[0].val % i == 0) {
      w[i] = 0;
      w[g[0].val / i] = 0;
    }
  }
  dfs2(0);
  for (int i : ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
