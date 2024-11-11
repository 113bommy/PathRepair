#include <bits/stdc++.h>
using namespace std;
long long c[555][555];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  c[0][0] = 1;
  for (int i = 1; i < 555; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  int n;
  cin >> n;
  cout << c[n - 1 + 5][5] * 1ll * c[n - 1 + 3][3] << endl;
  return 0;
}
