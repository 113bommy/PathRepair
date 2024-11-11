#include <bits/stdc++.h>
using namespace std;
long long int q, a, x, y;
vector<int> G[10001];
int main() {
  cin >> q;
  for (int i = 1; i < q; i++) {
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= q; i++)
    for (int j = 0; j < G[i].size(); j++) a += G[G[i][j]].size() - 1;
  cout << a / 2;
}
