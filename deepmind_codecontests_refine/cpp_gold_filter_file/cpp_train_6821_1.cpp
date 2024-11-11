#include <bits/stdc++.h>
using namespace std;
pair<int, int> row[5005], col[5005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for (long long int i = 1; i <= 5001; i++) {
    row[i] = {0, k};
    col[i] = {0, k};
  }
  while (k--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int r, a;
      cin >> r >> a;
      row[r] = {a, k};
    } else {
      int c, a;
      cin >> c >> a;
      col[c] = {a, k};
    }
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      cout << (row[i].second < col[j].second ? row[i].first : col[j].first)
           << " ";
    }
    cout << "\n";
  }
  return 0;
}
