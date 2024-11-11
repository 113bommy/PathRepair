#include <bits/stdc++.h>
using namespace std;
const long long sz = 3e5 + 5;
char s[sz];
int d[30][sz], a[sz];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
      d[s[i] - 'a'][i] = 1;
      for (int j = 0; j < 30; j++) {
        if (i) d[j][i] += d[j][i - 1];
      }
    }
    int ans[30] = {0};
    a[m] = n;
    for (int i = 0; i <= m; i++) {
      for (int j = 0; j < 30; j++) {
        ans[j] += d[j][a[i] - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 30; j++) {
        d[j][i] = 0;
      }
    }
    for (int i = 0; i < 26; i++) printf("%d ", ans[i]);
    puts("");
  }
}
