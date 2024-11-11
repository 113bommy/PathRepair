#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
char s[110][110];
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++) {
    long long cnt = 0;
    for (int j = 1; j <= n; j++)
      if (s[i][j] == 'C') cnt++;
    ans += (cnt - 1) * cnt / 2;
  }
  for (int i = 1; i <= n; i++) {
    long long cnt = 0;
    for (int j = 1; j <= n; j++)
      if (s[j][i] == 'C') cnt++;
    ans += (cnt - 1) * cnt / 2;
  }
  cout << ans << endl;
  return 0;
}
