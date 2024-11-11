#include <bits/stdc++.h>
using namespace std;
const string yno[2] = {"NO\n", "YES\n"};
int n, a, b, f[5005], pre[5005][26], z[5005][5005];
char s[5005];
void initz(int b, int z[]) {
  int c, r = c = 0;
  for (int i = b + 1; i <= n; i++) {
    if (r < i) {
      c = r = i;
      for (; r <= n && s[r] == s[r - c + b]; r++)
        ;
      z[i] = r - c, r--;
    } else {
      int k = i - c + b;
      if (z[k] < r - i + 1)
        z[i] = z[k];
      else {
        c = i;
        for (; r <= n && s[r] == s[r - c + 1]; r++)
          ;
        z[i] = r - c, r--;
      }
    }
  }
}
void process() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 25; j++) pre[i][j] = pre[i - 1][j];
    pre[i][s[i] - 'a'] = i;
  }
  for (int i = 1; i <= n; i++) initz(i, z[i]);
  for (int i = n; i >= 1; i--) {
    f[i] = a + f[i + 1];
    for (int j = 1; j <= i; j++) {
      int tmp = min(z[j][i], i - j);
      f[i] = min(f[i], b + f[i + tmp]);
    }
  }
  cout << f[1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  process();
  return 0;
}
