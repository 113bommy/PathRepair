#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, i, j, key, val, f, s;
  cin >> n >> m >> k;
  int A[n + 1][m + 1];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> A[i][j];
    }
  }
  pair<int, int> log[k];
  for (i = 0; i < k; i++) {
    cin >> f >> s;
    log[i] = make_pair(f, s);
  }
  int emp[20003] = {0}, chat[11] = {0}, res = 0;
  for (i = 0; i < k; i++) {
    emp[log[i].first]++;
    chat[log[i].second]++;
  }
  for (i = 1; i <= n; i++) {
    res = 0;
    for (j = 1; j <= m; j++) {
      res += A[i][j] * chat[j];
    }
    res -= emp[i];
    cout << res << " ";
  }
  return 0;
}
