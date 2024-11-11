#include <bits/stdc++.h>
using namespace std;
int N = 1000000007, n;
vector<vector<int> > dp1(5002, vector<int>(5002)), dp2(5002, vector<int>(5002));
vector<char> vec(5002);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> vec[i];
  }
  dp1[0][0] = 1;
  for (int i = 0; i < n - 1; i++) {
    dp2[i][n - 1] = dp1[i][n - 1];
    for (int j = n - 2; j >= 0; j--) {
      dp2[i][j] = (dp2[i][j + 1] + dp1[i][j]) % N;
    }
    if (vec[i] == 'f') {
      dp1[i + 1][0] = 0;
      for (int j = 1; j < n; j++) {
        dp1[i + 1][j] = dp1[i][j - 1];
      }
    } else {
      for (int j = 0; j < n; j++) {
        dp1[i + 1][j] = dp2[i][j];
      }
    }
  }
  int res = 0;
  for (int j = 0; j < n; j++) {
    res = (res + dp1[n - 1][j]) % N;
  }
  cout << res << endl;
}
