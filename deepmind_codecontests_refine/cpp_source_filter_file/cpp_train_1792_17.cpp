#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5) + 10;
char s[N];
int n, a[N], l[N], r[N];
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] != s[i - 1]) res = i;
    l[i] = res;
  }
  for (int i = n; i > 0; i--) {
    if (s[i] != s[i + 1]) res = i;
    r[i] = res;
  }
  long long ans = 0;
  int x = 1, y = n;
  while (x <= y) {
    if (r[x] == y) {
      if (y - x + 1 >= 3) ans = y - x + 2;
      break;
    }
    if (s[x] != s[y] || r[x] - l[x] + 1 + r[y] - l[y] + 1 <= 2) break;
    x = r[x] + 1, y = l[y] - 1;
  }
  cout << ans;
  return 0;
}
