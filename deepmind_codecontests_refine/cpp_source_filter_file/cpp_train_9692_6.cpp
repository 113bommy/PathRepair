#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, l;
  string s[125];
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'B') {
        l = j;
        while (l < m && s[i][j] == 'B') l++;
        l--;
        printf("%d %d\n", (2 * i + l - j + 1) / 2, (j + l + 1) / 2);
        return 0;
      }
    }
  }
  return 0;
}
