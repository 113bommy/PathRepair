#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 2e5 + 7;
int a[maxn];
char p[maxn], t[maxn], s[maxn];
int len;
bool check(int k) {
  for (int i = 1; i <= len; i++) s[i] = t[i];
  for (int i = 1; i <= k; i++) s[a[i]] = ' ';
  int j = 1;
  for (int i = 1; i <= len; i++) {
    if (s[i] == p[j]) j++;
    if (j > strlen(p + 1)) return true;
  }
  return false;
}
int main() {
  scanf("%s%s", t + 1, p + 1);
  len = strlen(t + 1);
  for (int i = 1; i <= len; i++) scanf("%d", a + i);
  int l = 0, r = len, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
