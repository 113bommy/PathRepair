#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main() {
  int n, cnt[4];
  while (~scanf("%d", &n)) {
    scanf("%s", s);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A')
        cnt[0]++;
      else if (s[i] == 'C')
        cnt[1]++;
      else if (s[i] == 'G')
        cnt[2]++;
      else if (s[i] == 'T')
        cnt[3]++;
    }
    int k = 0, ma = -1;
    for (int i = 0; i < 4; ++i) {
      if (cnt[i] > ma)
        k = 1, ma = cnt[i];
      else if (cnt[i] == ma)
        k++;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) ans = ans * k % 1000000007;
    printf("%d\n", ans);
  }
  return 0;
}
