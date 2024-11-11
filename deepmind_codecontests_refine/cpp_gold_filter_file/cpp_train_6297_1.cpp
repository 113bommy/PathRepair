#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++)
    os << *i << (i == end(v) - 1 ? "" : " ");
  return os;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto i = begin(v); i != end(v); i++) is >> *i;
  return is;
}
vector<pair<int, int>> edg[101000];
vector<bool> visited(101000);
vector<int> components(101000, -1);
vector<int> cnts(101000, 0);
int n, m;
void dfs1(int i, int component) {
  if (visited[i]) return;
  visited[i] = true;
  components[i] = component;
  for (auto x : edg[i]) {
    if (x.second != 1) continue;
    dfs1(x.first, component);
  }
}
vector<int> bip_check(101000, -1);
bool check_bipartite(int i, int val) {
  if (bip_check[i] >= 0) {
    if (bip_check[i] == val) return true;
    return false;
  }
  bip_check[i] = val;
  for (auto x : edg[i]) {
    int next = val;
    if (x.second == 0) next = !val;
    if (!check_bipartite(x.first, next)) return false;
  }
  return true;
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin >> n >> m;
  vector<pair<int, int>> zeroedg;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edg[a].push_back({b, c});
    edg[b].push_back({a, c});
    if (c == 0) zeroedg.push_back({a, b});
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (bip_check[i] >= 0) continue;
    if (!check_bipartite(i, 0)) {
      cout << "0";
      return 0;
    }
    c++;
  }
  long long ans = 1;
  for (int i = 0; i < c - 1; i++) {
    ans = (ans * 2LL) % 1000000007;
  }
  cout << ans;
  return 0;
}
