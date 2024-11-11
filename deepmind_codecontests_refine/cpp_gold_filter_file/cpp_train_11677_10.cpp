#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int x = 1;
  int y = 1;
  int levely = 1;
  int levelx = 1;
  vector<pair<int, int> > ans;
  int left = n * m;
  for (int i = 1; i <= m / 2; i++) {
    for (int j = 1; j <= n; j++) {
      ans.push_back({j, i});
      ans.push_back({n - j + 1, m - i + 1});
    }
  }
  if (m % 2 == 1) {
    for (int j = 1; j <= n / 2; j++) {
      ans.push_back({j, m / 2 + 1});
      ans.push_back({n - j + 1, m / 2 + 1});
    }
    if (n % 2 == 1) ans.push_back({n / 2 + 1, m / 2 + 1});
  }
  for (auto elem : ans) cout << elem.first << " " << elem.second << "\n";
}
