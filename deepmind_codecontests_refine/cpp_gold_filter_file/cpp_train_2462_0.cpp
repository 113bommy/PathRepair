#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000010];
int vis[1000010], cunt[1000010], par[100010];
int main() {
  int n, i;
  cin >> n;
  for (i = 2; i <= n; i++) {
    int e;
    cin >> e;
    cunt[i] = cunt[e] + 1;
    par[cunt[i]]++;
  }
  int ans = 1;
  for (i = 1; i <= n; i++) ans += par[i] % 2;
  cout << ans << endl;
  return 0;
}
