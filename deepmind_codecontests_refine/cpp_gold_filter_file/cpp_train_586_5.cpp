#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int base = 131;
const int mod = 1e9 + 7;
char s[N];
int n, ans[N / 2];
long long h[N], p[N];
long long get(int l, int r) {
  return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * base % mod;
  for (int i = 1; i <= n; i++)
    h[i] = (h[i - 1] * base % mod + s[i] - 'a') % mod;
  int l, r;
  int mid = n + 1 >> 1;
  if (n % 2 == 0) {
    l = n >> 1, r = l + 1;
    if (s[l] == s[r])
      ans[mid] = 1;
    else
      ans[mid] = -1;
  } else
    ans[mid] = -1, l = r = mid;
  for (int i = mid - 1; i >= 1; i--) {
    l--, r++;
    for (int j = ans[i + 1] + 2; j >= -1; j -= 2) {
      if (get(l, l + j - 1) == get(r - j + 1, r) || j == -1) {
        ans[i] = j;
        break;
      }
    }
  }
  for (int i = 1; i <= mid; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
