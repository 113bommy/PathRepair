#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int sum[maxn];
int c[maxn];
char s[maxn];
int main() {
  int len;
  scanf("%d", &len);
  cin >> s + 1;
  int ans = 0;
  sum[0] = maxn / 2;
  for (int i = 1; i <= len; i++) {
    if (s[i] == '0')
      sum[i] = sum[i - 1] - 1;
    else
      sum[i] = sum[i - 1] + 1;
    if (c[sum[i]] == 0) c[sum[i]] = i;
    ans = max(ans, i - c[sum[i]]);
    if (sum[i] == 0) ans = max(ans, i);
  }
  cout << ans << "\n";
  return 0;
}
