#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, k, m, t, x, b[N], a[N], c[N];
int i, j;
vector<int> ind, g;
map<int, long long> C;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = 1;
    if (a[i] == 0) ind.push_back(i);
  }
  for (i = 1; i <= n; i++) {
    if (b[i] == 0) {
      g.push_back(i);
    }
  }
  for (i = 0; i < ind.size(); i++) {
    if (g[i] == ind[i] || g[i + 1] == ind[i + 1]) {
      swap(g[i], g[i + 1]);
    }
    a[ind[i]] = g[i];
  }
  a[ind[ind.size() - 1]] = g[g.size() - 1];
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  ;
}
