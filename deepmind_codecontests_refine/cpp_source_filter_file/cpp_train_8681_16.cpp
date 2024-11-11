#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long a, b, c, i, j, k, l, m, t, x, y, n, z;
  string s;
  cin >> n;
  char a1[n][n];
  vector<vector<long long> > a2, a3;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) cin >> a1[i][j];
  a = 0;
  b = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a1[i][j] == '.') {
        vector<long long> temp(2);
        temp[0] = i;
        temp[1] = j;
        a2.push_back(temp);
        a++;
        break;
      }
    }
  }
  for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
      if (a1[j][i] == '.') {
        vector<long long> temp(2);
        temp[0] = i;
        temp[1] = j;
        a3.push_back(temp);
        b++;
        break;
      }
    }
  }
  if (a == n) {
    for (i = 0; i < a2.size(); i++) {
      cout << a2[i][0] + 1 << " " << a2[i][1] + 1 << endl;
    }
  } else if (b == n) {
    for (i = 0; i < a3.size(); i++) {
      cout << a3[i][0] + 1 << " " << a3[i][1] + 1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
