#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<pair<long long int, long long int> > row(n);
  vector<pair<long long int, long long int> > col(m);
  int i, j;
  for (i = 0; i < n; i++) {
    row[i].first = 0;
    row[i].second = 0;
  }
  for (i = 0; i < m; i++) {
    col[i].first = 0;
    col[i].second = 0;
  }
  for (i = 1; i <= k; i++) {
    long long int t, index, val;
    cin >> t >> index >> val;
    index--;
    if (t == 1) {
      row[index].first = i;
      row[index].second = val;
    } else {
      col[index].first = i;
      col[index].second = val;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (row[i].first >= col[j].first) {
        cout << row[i].second;
      } else {
        cout << col[j].second;
      }
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
