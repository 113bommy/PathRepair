#include <bits/stdc++.h>
using namespace std;
char s[500001];
int n, t;
bool judge(int x) {
  int far = 0, far2 = 0, sum = x;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'S') sum++;
    if (s[i] == 'H') sum--;
    if (sum == 0 || s[i] == 'H') far = i;
    if (s[i] == 'H') far2 = i;
  }
  if (sum < 0) return false;
  int las = 0, res = 0, ans = 999999999;
  sum = x;
  for (int i = 1; i <= far; i++) {
    res++;
    if (s[i] == 'S') {
      sum++;
      if (sum == 0) {
        res += (i - las) * 2;
        las = 0;
      }
    }
    if (s[i] == 'H') {
      sum--;
      if (sum == -1) {
        ans = min(ans, res + (far - i) * 2);
        las = i;
      }
    }
    if (i >= far2 && las == 0) ans = min(ans, res - (i - far2));
  }
  return ans <= t;
}
signed main() {
  cin >> n >> t;
  cin >> s + 1;
  int l = -1, r = 100001;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (judge(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%d", (r != 100001) ? r : -1);
  return 0;
}
