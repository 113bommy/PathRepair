#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> ans[10010];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    ans[i].push_back(6 * i + 1);
    ans[i].push_back(6 * i + 2);
    ans[i].push_back(6 * i + 3);
    ans[i].push_back(6 * i + 5);
  }
  cout << k * ans[n - 1][3] << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) cout << k * ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
