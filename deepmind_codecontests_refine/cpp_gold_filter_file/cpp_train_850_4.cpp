#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N];
int pos[2][N];
int cnt[2];
int sum[2][N];
int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'B') a[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    pos[a[i]][++cnt[a[i]]] = i;
    for (int j = 0; j <= 1; j++) {
      sum[j][i] = sum[j][i - 1];
    }
    sum[a[i]][i]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 2; j <= cnt[i]; j++) {
      if (sum[1 - i][pos[i][j]] - sum[1 - i][pos[i][j - 1]] > 0) {
        ans += pos[i][j - 1];
      } else {
        if (sum[1 - i][pos[i][j - 1]] == 0) {
          ans += pos[i][j - 1];
        } else {
          ans += pos[i][j - 1] - 1;
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
