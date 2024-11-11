#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
vector<int> num;
int a[5010][5010];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    ans ^= a[i][1];
    num.push_back(1);
  }
  if (ans != 0) {
    cout << "TAK" << endl;
    for (auto x : num) {
      cout << x << " ";
    }
    cout << endl;
  } else {
    int sign = 0;
    for (i = 1; i <= n; i++) {
      for (j = 2; j <= m; j++) {
        if (ans ^ a[i][1] ^ a[i][j]) {
          sign = 1;
          num[i] = j;
          break;
        }
      }
      if (sign == 1) break;
    }
    if (!sign) {
      cout << "NIE" << endl;
    } else {
      cout << "TAK" << endl;
      for (auto x : num) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
}
