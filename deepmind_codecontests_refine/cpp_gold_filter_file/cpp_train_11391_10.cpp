#include <bits/stdc++.h>
using namespace std;
string second;
int n;
const int maxn = 100100;
int sum[maxn][3];
int main() {
  cin >> second;
  for (int i = 0; i < second.size(); i++) {
    for (int j = 0; j < 3; j++) {
      sum[i + 1][j] = sum[i][j];
    }
    sum[i + 1][(int)(second[i] - 'x')]++;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    if (len < 3) {
      cout << "YES" << endl;
      continue;
    }
    int num = (len + 2) / 3;
    bool ff = 0;
    for (int j = 0; j < 3; j++) {
      if (sum[r][j] - sum[l - 1][j] > num ||
          sum[r][j] - sum[l - 1][j] < num - 1) {
        cout << "NO" << endl;
        ff = 1;
        break;
      }
    }
    if (!ff) {
      cout << "YES" << endl;
    }
  }
  return 0;
}
