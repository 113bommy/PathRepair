#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<int>& v1, const vector<int>& v2) {
  return v1[1] > v2[1];
}
int main() {
  int m, n;
  cin >> n >> m;
  vector<vector<int> > a(m, vector<int>(2, 0));
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  sort(a.begin(), a.end(), sortcol);
  long long num_matches = 0;
  for (int i = 0; i < m; i++) {
    if (a[i][0] <= n) {
      num_matches += a[i][0] * a[i][1];
      n -= a[i][0];
      if (n == 0) break;
    } else {
      num_matches += n * a[i][1];
      break;
    }
  }
  cout << num_matches << endl;
  return 0;
}
