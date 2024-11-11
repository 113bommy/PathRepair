#include <bits/stdc++.h>
using namespace std;
int u[2003][2003], u1[2003][2003];
char s[2003][2003];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  int ans = 0, temp;
  for (int i = 1; i <= n; i++) {
    temp = 0;
    int j = n;
    while (j > i) {
      if (i + 1 <= n) u[i + 1][j] = u[i][j];
      u[i][j] ^= temp;
      if ((s[i][j] - '0') != u[i][j]) {
        if (i + 1 <= n) u[i + 1][j] = 1 ^ u[i][j];
        temp = temp ^ 1;
        ans++;
      }
      j--;
    }
    u[i][j] ^= temp;
  }
  for (int i = n; i >= 1; i--) {
    temp = 0;
    int j = 1;
    while (j < i) {
      if (i - 1 >= 1) u1[i - 1][j] = u1[i][j];
      u1[i][j] ^= temp;
      if (s[i][j] - '0' != u1[i][j]) {
        if (i - 1 >= 1) u1[i - 1][j] = 1 ^ u1[i][j];
        temp = temp ^ 1;
        ans++;
      }
      j++;
    }
    u1[i][j] ^= temp;
  }
  for (int i = 1; i <= n; i++) {
    if ((s[i][i] - '0') != (u[i][i] ^ u1[i][i])) ans++;
  }
  cout << ans << endl;
  return 0;
}
