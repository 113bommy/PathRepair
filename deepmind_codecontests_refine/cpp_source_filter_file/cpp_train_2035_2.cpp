#include <bits/stdc++.h>
using namespace std;
vector<int> g[100028];
int main() {
  long long n, c = 0, u, v;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> v >> u;
    v--;
    u--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n - 1; i++)
    if (g[i].size() >= 2) {
      c += (g[i].size() * (g[i].size() - 1)) / 2;
    }
  cout << c;
}
