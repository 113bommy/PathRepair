#include <bits/stdc++.h>
using namespace std;
int vis[100010];
int main() {
  int n, m, k, i, M = 0, z = 0;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> k;
    vis[k]++;
    M = max(M, vis[k]);
  }
  for (i = 1; i <= 100; i++)
    if (vis[i]) z++;
  while (M % m != 0) M++;
  cout << z * M - n;
}
