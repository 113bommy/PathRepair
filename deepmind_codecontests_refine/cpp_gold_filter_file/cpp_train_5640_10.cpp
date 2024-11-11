#include <bits/stdc++.h>
const long long mx = 200005;
using namespace std;
vector<int> a[mx];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, u, v;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].size() == 2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
  return 0;
}
