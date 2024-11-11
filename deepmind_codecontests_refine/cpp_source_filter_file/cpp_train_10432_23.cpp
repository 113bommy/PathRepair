#include <bits/stdc++.h>
using namespace std;
int n, sol;
int l1[2002], c1[2002], l2[2002], c2[2002];
char s[2002][2002];
int main() {
  cin >> n;
  int i, j, l;
  for (i = 1; i <= n; i++) cin >> s[i] + 1;
  for (l = n; l > 2; l--)
    for (i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      if ((s[i][j] + l1[i] + c1[j]) & 1) {
        sol++;
        l1[i]++;
        c1[j]++;
      }
      if ((s[j][i] + l2[j] + c2[i]) & 1) {
        sol++;
        l2[j]++;
        c2[i]++;
      }
    }
  for (i = 1; i <= n; i++)
    if ((s[i][i] + l1[i] + c1[i] + l2[i] + c2[i]) & 1) sol++;
  cout << sol;
  return 0;
}
