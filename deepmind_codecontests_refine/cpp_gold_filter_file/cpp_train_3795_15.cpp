#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
const int inf = (1ll < 61);
int n, c;
char a[MAX][MAX];
int main() {
  cin >> n;
  memset(a, '*', sizeof(a));
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = 0; j <= c; j++) {
      a[i][(n - 1) / 2 + j] = 'D';
      a[i][(n - 1) / 2 - j] = 'D';
      a[n - 1 - i][(n - 1) / 2 + j] = 'D';
      a[n - 1 - i][(n - 1) / 2 - j] = 'D';
    }
    c++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j];
    cout << endl;
  }
  return 0;
}
