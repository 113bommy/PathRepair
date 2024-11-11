#include <bits/stdc++.h>
using namespace std;
pair<long int, long int> row[5001];
pair<long int, long int> col[5001];
int main() {
  long int n, m, k, i, j;
  cin >> n >> m >> k;
  for (i = 0; i < k; i++) {
    long int num, r1, a1;
    cin >> num >> r1 >> a1;
    if (num == 1) {
      row[r1] = make_pair(i, a1);
    } else {
      col[r1] = make_pair(i, a1);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (row[i].first < col[j].first)
        cout << col[j].second << " ";
      else
        cout << row[i].second << " ";
    }
    cout << endl;
  }
  return 0;
}
