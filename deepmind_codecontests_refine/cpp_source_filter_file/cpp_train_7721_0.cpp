#include <bits/stdc++.h>
using namespace std;
char str[1005][1005];
int main() {
  long long n, m, i, j, cn[10], ans = 0, sum = 0, a[1100];
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> str[i];
  for (i = 1; i <= m; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    for (j = 0; j < 5; j++) {
      cn[i] = 0;
    }
    ans = 0;
    for (j = 1; j <= n; j++) {
      cn[str[j][i] - 'A']++;
    }
    for (j = 0; j < 5; j++) {
      ans = max(ans, cn[i]);
    }
    sum += ans * a[i + 1];
  }
  cout << sum << endl;
  return 0;
}
