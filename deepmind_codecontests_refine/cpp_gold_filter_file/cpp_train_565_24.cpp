#include <bits/stdc++.h>
using namespace std;
int n;
char a[101010], b[101010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int T = 0, H = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == 'H')
      H++;
    else
      T++;
  int ans = 1000000000;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) b[j] = ' ';
    for (int j = i, tot = 1; tot <= H; tot++, j = j % n + 1) b[j] = 'H';
    for (int j = 1; j <= n; j++)
      if (b[j] == ' ') b[j] = 'T';
    int cur = 0;
    for (int j = 1; j <= n; j++)
      if (a[j] != b[j]) cur++;
    cur /= 2;
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
