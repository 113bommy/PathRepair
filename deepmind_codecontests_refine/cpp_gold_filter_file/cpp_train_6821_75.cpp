#include <bits/stdc++.h>
using namespace std;
int n, m, k;
pair<int, int> col[5000];
pair<int, int> row[5000];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0; i < 5000; i++) row[i] = col[i] = make_pair(0, 0);
  for (int i = 1; i <= k; i++) {
    int com, num, val;
    cin >> com >> num >> val;
    if (com == 1)
      row[num - 1] = make_pair(val, i);
    else
      col[num - 1] = make_pair(val, i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ans = 0;
      if (row[i].second > col[j].second)
        ans = row[i].first;
      else
        ans = col[j].first;
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
