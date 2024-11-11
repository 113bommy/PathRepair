#include <bits/stdc++.h>
using namespace std;
const int OO = (int)2e9;
const double eps = 1e-9;
bool vis[101];
int main() {
  int i, j, n, k, x;
  cin >> n >> k;
  vector<vector<int> > V(k + 1);
  for ((i) = (1); (i) < (k + 1); (i)++) {
    cin >> x;
    vis[x] = 1;
    V[i].push_back(x);
  }
  for ((i) = (1); (i) < (k + 1); (i)++) {
    if (((int)(V[i]).size()) == n) continue;
    for ((j) = (1); (j) < (n * k + 1); (j)++) {
      if (!vis[j]) vis[j] = 1, V[i].push_back(j);
      if (((int)(V[i]).size()) == n) break;
    }
  }
  for ((i) = (1); (i) < (k + 1); (i)++)
    for ((j) = 0; (j) < (n); (j)++) cout << V[i][j] << " \n"[j == n - 1];
  return 0;
}
