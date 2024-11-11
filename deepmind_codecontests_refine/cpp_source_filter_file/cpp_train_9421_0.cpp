#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
int a[55][55];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for (int d = 1; d <= n * n; d++) {
    int x, y;
    cin >> x >> y;
    if (a[x][y] == 0) {
      ans.push_back(d);
      a[x][y] = 1;
      for (int i = 1; i <= n; i++) {
        if (x - i >= 0) a[x - i][y] = 1;
        if (x + i <= n) a[x + i][y] = 1;
        if (y - i >= 0) a[x][y - i] = 1;
        if (x + i <= n) a[x][y + 1] = 1;
      }
    }
  }
  for (auto i : ans) cout << i << " ";
  cout << endl;
  ;
  return 0;
}
