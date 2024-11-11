#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[N], t[N];
int q, l1, l2, len;
unsigned long long a[N], b[N];
int main() {
  scanf("%s%s", s, t);
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i < n - 63; i++)
    for (int j = i; j < i + 64; j++) a[i] = a[i] << 1 | (s[j] - '0');
  for (int i = 0; i < m - 63; i++)
    for (int j = i; j < i + 64; j++) b[i] = b[i] << 1 | (t[j] - '0');
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d", &l1, &l2, &len);
    int ans = 0;
    while (len >= 64) {
      ans += __builtin_popcountll(a[l1] ^ b[l2]);
      len -= 64;
      l1 += 64;
      l2 += 64;
    }
    for (int i = 0; i < len; i++) ans += s[l1] != t[l2], l1++, l2++;
    printf("%d\n", ans);
  }
}
