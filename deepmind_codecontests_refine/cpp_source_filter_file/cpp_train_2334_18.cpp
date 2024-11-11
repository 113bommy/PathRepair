#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, s[1000], i, j, l, ans = 0, p = 0;
  char a[100][100];
  cin >> k;
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= 4; j++) cin >> a[i][j];
  for (l = '1'; l <= '9'; l++) {
    for (i = 1; i <= 4; i++) {
      for (j = 1; j <= 4; j++) {
        if (l == a[i][j]) s[p]++;
      }
    }
    p++;
  }
  for (l = 1; l <= p; l++)
    if (s[l] <= 2 * k) ans++;
  if (ans == 9)
    cout << "YES";
  else
    cout << "NO";
}
