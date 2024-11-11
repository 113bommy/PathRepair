#include <bits/stdc++.h>
using namespace std;
int n, a[200005], maxx, minn;
char s[200005];
int main() {
  int l = -1000000000, r = 1000000000;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  for (int i = 5; i <= n; i++) {
    int sum = 0;
    for (int j = i - 4; j < i; j++) sum += s[j] - 48;
    if (sum == 0 && s[i] == '1') {
      maxx = -1000000000;
      for (int j = i - 4; j < i; j++) maxx = max(a[j], maxx);
      l = max(maxx + 1, l);
    } else if (sum == 4 && s[i] == '0') {
      minn = 1000000000;
      for (int j = i - 4; j < i; j++) minn = min(a[j], minn);
      r = min(minn - 1, r);
    }
  }
  printf("%d %d", l, r);
}
