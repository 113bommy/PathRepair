#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
struct DSU {
 private:
  vector<int> parent, size;
  int N;

 public:
  DSU(int n) {
    N = n;
    size.resize(N + 1, 1);
    parent.resize(N + 1);
    for (int i = 0; i <= N; i++) parent[i] = i;
  }
  void makeParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
      if (size[a] < size[b]) swap(a, b);
      parent[b] = a;
      size[a] += size[b];
    }
  }
  int getParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
  }
  vector<vector<int>> components() {
    vector<vector<int>> component(N + 1);
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++) component[getParent(i)].push_back(i);
    for (int i = 1; i <= N; i++)
      if (!component[i].empty()) ans.push_back(component[i]);
    return ans;
  }
};
bool islucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int n;
  cin >> n;
  DSU d(n);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (!islucky(c)) d.makeParent(a, b);
  }
  auto v = d.components();
  ll ans = 0;
  for (auto &i : v) ans += (ll)i.size() * (n - i.size()) * (n - i.size() - 1);
  cout << ans;
}
