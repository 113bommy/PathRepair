#include <bits/stdc++.h>
using namespace std;
char map1[51][51];
bitset<51> map2[51];
int n, m;
bool x[51];
bool y[51];
int main() {
  int s;
  scanf("%d%d", &m, &n);
  for (register int i = 1; i <= m; i++) {
    scanf("%s", map1[i] + 1);
    for (register int j = 1; j <= n; j++) {
      if (map1[i][j] == '#') {
        map2[i][j] = true;
      }
    }
  }
  for (register int i = 1; i <= m - 1; i++) {
    for (register int j = i + 1; j <= m; j++) {
      if ((map2[i] & map2[j]).count() && (map2[i] ^ map2[j]).count()) {
        printf("No");
        return 0;
      }
    }
  }
  printf("Yes");
  return 0;
}
