#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, k;
char ch;
int c[27];
int main() {
  scanf("%d%d\n", &n, &k);
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; ++i) {
    scanf("%c", &ch);
    c[ch - 'A']++;
  }
  long long ans = 0;
  while (k > 0) {
    int Max = -1, pos = 0;
    for (int i = 0; i < 27; ++i)
      if (c[i] > Max) {
        Max = c[i];
        pos = i;
      }
    c[pos] = 0;
    ans += min(Max, k) * min(Max, k);
    k -= min(Max, k);
  }
  printf("%I64d", ans);
  return 0;
}
