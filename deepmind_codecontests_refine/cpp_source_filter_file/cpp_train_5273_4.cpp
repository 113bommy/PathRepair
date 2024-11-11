#include <bits/stdc++.h>
using namespace std;
template <int SZ>
struct DSU {
  int par[SZ];
  int size[SZ];
  DSU() {
    for (int i = 0; i < SZ; i++) par[i] = i, size[i] = 1;
  }
  int get(int node) {
    if (par[node] != node) par[node] = get(par[node]);
    return par[node];
  }
  bool connected(int n1, int n2) { return (get(n1) == get(n2)); }
  int sz(int node) { return size[get(node)]; }
  void unite(int n1, int n2) {
    n1 = get(n1);
    n2 = get(n2);
    if (n1 == n2) return;
    if (rand() % 2) {
      par[n1] = n2;
      size[n2] += size[n1];
    } else {
      par[n2] = n1;
      size[n1] += size[n2];
    }
  }
};
DSU<1000> d;
bool same(char a, char b) { return d.connected(a - '0', b - '0'); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < 26; i++) {
    d.unite(('a' + i) - '0', ('A' + i) - '0');
  }
  d.unite('O' - '0', '0' - '0');
  d.unite('I' - '0', 'l' - '0');
  d.unite('1' - '0', 'I' - '0');
  for (int i = 0; i < n; i++) {
    string k;
    cin >> k;
    if (k.length() != s.length()) continue;
    bool diff = false;
    for (int j = 0; j < k.length(); j++) {
      if (!same(s[i], k[i])) diff = true;
    }
    if (!diff) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
