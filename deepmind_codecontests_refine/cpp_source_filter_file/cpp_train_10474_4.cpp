#include <bits/stdc++.h>
using namespace std;
int a[500100];
int n;
vector<int> g[200100];
int d[200100];
int cnt = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int ind = lower_bound(d + 1, d + n + 1, a[i]) - d;
    d[ind - 1] = a[i];
    g[ind - 1].push_back(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[i].size(); j++) cout << g[i][j] << " ";
    cout << endl;
  }
}
