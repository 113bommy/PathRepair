#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N];
int n, w[N];
bool ctrl(int x) {
  int pk = 0, exp = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '*' && i > exp && !pk) pk = i;
    if (s[i] == 'P') {
      if (pk == 0)
        exp = i + x;
      else {
        int dis = i - pk;
        if (dis > x)
          return 0;
        else {
          if (x > dis * 3)
            exp = i + x - dis * 2;
          else
            exp = i + (x - dis) / 2;
          pk = 0;
        }
        if (exp >= n) return 1;
      }
    }
  }
  if (pk) return 0;
  return 1;
}
int main() {
  scanf("%d\n%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    w[i] = w[i - 1] + (s[i] == '*');
  }
  int l = 0, r = n << 1, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (ctrl(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d", ans);
  return 0;
}
