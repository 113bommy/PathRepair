#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 5;
char str[MAXN];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", str + 1);
  int block = 1;
  for (int i = 2; i <= n; i++) {
    if (str[i] != str[i - 1]) block++;
  }
  long long ans = 1LL * block * n * (m - 1);
  int cur = 0;
  for (int i = 2; i <= n; i++) {
    if (str[i] == str[i - 1])
      cur = 0;
    else {
      if (i >= 3 && str[i] != str[i - 2])
        cur = 1;
      else
        cur++;
    }
    ans -= cur;
  }
  printf("%lld\n", ans);
  return 0;
}
