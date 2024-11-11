#include <bits/stdc++.h>
using namespace std;
int edge, node, v[1001];
vector<int> g[1002];
void x(int xx) {
  v[xx] = 1;
  for (auto u : g[xx])
    if (!v[u]) x(u);
}
int main() {
  cin >> node >> edge;
  for (auto i = 0; i < edge; i++) {
    int s, d;
    cin >> s >> d;
    g[s].push_back(d);
    g[d].push_back(s);
  }
  x(1);
  for (int i = 1; i <= node; i++)
    if (!v[i]) {
      return cout << "no", 0;
    }
  if (edge == node - 1) return cout << "no", 0;
  cout << "yes";
}
