#include <bits/stdc++.h>
using namespace std;
constexpr unsigned long long int mod = 998244353;
vector<pair<int, int>> edges;
set<int> children[1000000];
void rootify(int i, int p = 0) {
  children[i].erase(p);
  for (int c : children[i]) {
    rootify(c, i);
  }
}
unsigned long long int fact[10001000];
unsigned long long int solve(int i) {
  unsigned long long int r = fact[children[i].size() + (i != 1)];
  for (int c : children[i]) {
    r = (r * solve(c)) % mod;
  }
  return r;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  fact[0] = 1;
  for (unsigned long long int i = 1; i < 1000000; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  int n;
  cin >> n;
  edges.resize(n - 1);
  for (auto &e : edges) {
    cin >> e.first >> e.second;
    children[e.first].insert(e.second);
    children[e.second].insert(e.first);
  }
  rootify(1);
  cout << (solve(1) * n) % mod << "\n";
}
