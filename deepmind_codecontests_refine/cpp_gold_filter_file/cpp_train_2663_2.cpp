#include <bits/stdc++.h>
using namespace std;
const int N = 1111, base = 1e9 + 7;
int n, a[26], f[N][3];
char s[N];
int main() {
  scanf("%d%s", &n, s);
  for (int i = 0; i < 26; ++i) scanf("%d", &a[i]);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (!i) continue;
    int len = 1e9 + 7;
    f[i][1] = -1e9 + 7;
    f[i][2] = 1e9 + 7;
    for (int j = i - 1; j >= 0; --j) {
      len = min(len, a[s[j] - 'a']);
      if (len < i - j) break;
      f[i][0] = (f[i][0] + f[j][0]) % base;
      f[i][1] = max(f[i][1], max(i - j, f[j][1]));
      f[i][2] = min(f[i][2], f[j][2] + 1);
    }
  }
  for (int i = 0; i < 3; ++i) printf("%d\n", f[n][i]);
  return 0;
}
