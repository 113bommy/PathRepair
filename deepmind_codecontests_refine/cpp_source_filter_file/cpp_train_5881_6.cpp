#include <bits/stdc++.h>
using namespace std;
int n, ans, f[100][100];
char s[10000], s1[10001];
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  scanf("%s", s1 + 1);
  for (int i = 1; i <= 9; i++) {
    for (int j = i; j <= 9; j++) {
      f[i][j] = min(j - i, i + 10 - j);
      f[j][i] = f[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += f[int(s[i]) - 48][int(s1[i]) - 48];
  }
  cout << ans;
  return 0;
}
