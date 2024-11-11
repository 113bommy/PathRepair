#include <bits/stdc++.h>
using namespace std;
int z[26][200001], w[26];
int main() {
  int n, m, i, j, a, le;
  char str[200001];
  scanf("%d %d", &n, &m);
  scanf("%s", str);
  for (i = 0; str[i]; i++) {
    z[str[i] - 'a'][w[str[i] - 'a']] = i;
    w[str[i] - 'a']++;
  }
  long long ans;
  int mi;
  while (m) {
    m--;
    ans = 0;
    scanf("%s", str);
    le = strlen(str);
    for (i = 0; str[i]; i++) {
      a = str[i] - 'a';
      if (w[a] == 0)
        ans += le;
      else {
        mi = abs(i - z[a][0]);
        ;
        for (j = 1; j < w[a]; j++) {
          mi = min(mi, abs(i - z[a][j]));
        }
        ans += mi;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
