#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string ans[n];
  int scores[m];
  int deep;
  int x[5];
  for (int i = 0; i < n; i++) {
    cin >> ans[i];
  }
  for (int i = 0; i < 5; i++) x[i] = 0;
  for (int i = 0; i < m; i++) cin >> scores[i];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char tmp = char(ans[j][i]);
      x[int(tmp) - 65]++;
    }
    int max = x[0];
    for (int i = 1; i < m; i++) {
      if (x[i] > max) max = x[i];
    }
    deep += max * scores[i];
    for (int i = 0; i < 5; i++) x[i] = 0;
  }
  cout << deep;
  return 0;
}
