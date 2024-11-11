#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> q(n + 1), inv(n + 1), s(n + 1), p(n + 1), tmp(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &q[i]);
    inv[q[i]] = i;
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
  for (int i = 1; i <= n; ++i) p[i] = i;
  if (p == s) {
    printf("NO\n");
    return 0;
  }
  int v1 = 1, v2 = 1;
  for (; v1 <= k; ++v1) {
    for (int i = 1; i <= n; ++i) tmp[i] = p[q[i]];
    if (tmp == s) {
      if (v1 == k || v1 > 1 && (k - v1) % 2 == 0) {
        printf("YES\n");
        return 0;
      }
      break;
    }
    swap(tmp, p);
  }
  for (int i = 1; i <= n; ++i) p[i] = i;
  for (; v2 <= k; ++v2) {
    for (int i = 1; i <= n; ++i) tmp[i] = p[inv[i]];
    if (tmp == s) {
      if (v2 == k || v2 > 1 && (k - v2) % 2 == 0) {
        printf("YES\n");
        return 0;
      }
      break;
    }
    swap(tmp, p);
  }
  if (v1 == 1 && v2 == 1)
    printf("NO\n");
  else if ((v1 == 1 && (k - v1) % 2 == 0 || v2 == 1 && (k - v2) % 2 == 0))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
