#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  string str[110];
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  int success[110] = {0};
  for (int i = 0; i < m; i++) {
    int maxi = -1;
    for (int j = 0; j < n; j++) {
      maxi = max(maxi, str[j][i] - '0');
    }
    for (int j = 0; j < n; j++) {
      if (str[j][i] - '0' == maxi) {
        success[j] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) ans += success[i];
  cout << ans << endl;
  return 0;
}
