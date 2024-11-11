#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long res = 0;
  vector<vector<long long> > vec(n, vector<long long>(m));
  vector<long long> ans(n, 1);
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      cin >> vec[i][j];
    }
    res = res ^ vec[i][0];
  }
  if (res == 0) {
    for (long long i = 0; i < n; ++i) {
      for (long long j = 1; j < m; ++j) {
        if (vec[i][j] != vec[i][0]) {
          ans[i] = j + 1;
          res = res ^ ans[i];
          break;
        }
      }
      if (ans[i] != 1) break;
    }
  }
  if (res) {
    cout << "TAK"
         << "\n";
    for (auto a : ans) {
      cout << a << " ";
    }
    cout << "\n";
  } else
    cout << "NIE"
         << "\n";
  return 0;
}
