#include <bits/stdc++.h>
using namespace std;
int n, m;
int check[15001];
vector<pair<int, int>> ans;
void f(int x, int y) {
  int i;
  if (y == 0) return;
  f(x, y - 1);
  f(x + (1 << (y - 1)) - 1, y - 1);
  for (i = 0; i < (1 << (y - 1)); i++) {
    ans.push_back({x + i, x + i + (1 << (y - 1))});
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int s = 0;
  int i, j;
  int t;
  for (t = 0; (1 << (t + 1)) <= n; t++)
    ;
  f(1, t);
  f(n - (1 << t) + 1, t);
  cout << ans.size() << endl;
  for (auto k : ans) {
    cout << k.first << " " << k.second << "\n";
  }
  return 0;
}
