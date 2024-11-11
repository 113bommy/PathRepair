#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d", &n), scanf("%d", &m);
  string s, t;
  cin >> s;
  cin >> t;
  int minC = INT_MAX, pos = -1;
  for (int i = 0; i < m; i++) {
    int c = 0;
    if (i + n > m) break;
    for (int k = i, j = 0; j < n; j++, k++) {
      if (s[j] != t[k]) c++;
    }
    if (c < minC) {
      minC = c;
      pos = i;
    }
  }
  printf("%d", minC), printf("\n");
  for (int i = pos, j = 0; j < n; j++, i++) {
    if (s[j] != t[i]) printf("%d", j + 1), printf(" ");
  }
  return 0;
}
