#include <bits/stdc++.h>
using namespace std;
vector<bool> a[600000];
vector<bool> b[600000];
int main() {
  memset(a, false, sizeof(a));
  memset(b, false, sizeof(b));
  char c;
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m + 1; j++) {
      a[i].push_back(false);
      b[i].push_back(false);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%c", &c);
      if (c != '.') {
        if (c == '1') {
          a[i - 1][j] = true;
          b[i][j - 1] = true;
        }
        if (c == '2') {
          a[i][j] = true;
          b[i][j - 1] = true;
        }
        if (c == '3') {
          a[i][j] = true;
          b[i][j] = true;
        }
        if (c == '4') {
          a[i - 1][j] = true;
          b[i][j - 1] = true;
        }
      }
    }
    scanf("\n");
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    int flag = 2;
    int last;
    for (int j = 0; j <= m; j++) {
      if (b[i][j]) {
        if (flag == 2) {
          flag = 1;
          last = j;
        } else {
          if ((j - last) % 2 != 0) flag = 0;
        }
      }
    }
    ans = ans * flag % 1000007;
  }
  for (int i = 1; i <= m; i++) {
    int flag = 2;
    int last;
    for (int j = 0; j <= n; j++) {
      if (a[j][i]) {
        if (flag == 2) {
          flag = 1;
          last = j;
        } else {
          if ((j - last) % 2 != 0) flag = 0;
        }
      }
    }
    ans = ans * flag % 1000007;
  }
  cout << ans << endl;
  return 0;
}
