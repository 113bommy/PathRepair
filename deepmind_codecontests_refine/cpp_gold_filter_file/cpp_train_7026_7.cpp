#include <bits/stdc++.h>
using namespace std;
const int LEN = 5000;
int n, m, a, b, res, ar1[LEN][LEN];
vector<int> ar[LEN];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    ar[a - 1].push_back(b - 1);
    ar[b - 1].push_back(a - 1);
    ar1[a - 1][b - 1] = ar1[b - 1][a - 1] = 1;
  }
  res = LEN * LEN;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < ar[i].size(); j++)
      for (int z = 0; z < ar[ar[i][j]].size(); z++)
        if (ar1[i][ar[ar[i][j]][z]])
          res = min(res, int(ar[i].size() + ar[ar[i][j]].size() +
                             ar[ar[ar[i][j]][z]].size()) -
                             6);
  if (res == LEN * LEN)
    cout << -1;
  else
    cout << res;
  return 0;
}
