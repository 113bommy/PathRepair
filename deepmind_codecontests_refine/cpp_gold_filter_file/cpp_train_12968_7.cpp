#include <bits/stdc++.h>
using namespace std;
long long m, b, c, n, i, j, k, l, p, o, sum;
string s[1000];
char a[1000][1000];
int main() {
  cin >> m >> n;
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'X') {
        sum++;
        if (o == 0 && p == 0) {
          o = i;
          p = j;
        }
        k = i;
        l = j;
      }
    }
  }
  for (i = o; i <= k; i++) {
    for (j = p; j <= l; j++) {
      if (a[i][j] != 'X') {
        cout << "NO";
        return 0;
      }
      sum--;
    }
  }
  if (sum != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
