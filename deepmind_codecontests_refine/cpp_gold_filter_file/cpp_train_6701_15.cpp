#include <bits/stdc++.h>
const int N = 110;
int n, k, a[N], b[N], q1[N], q2[N], qs[N], r[N], s, g, t;
bool work(int k, int *q) {
  for (int i = 1; i <= n; i++) qs[i] = q[i];
  if (k % 2)
    for (int i = 1; i <= n; i++) q[i] = a[q[i]];
  for (int i = k % 2; i <= k; i += 2) {
    bool f = false;
    for (int i = 1; i <= n; i++)
      if (b[i] != q[i]) f = true;
    if (!f) return true;
    for (int i = 1; i <= n; i++) q[i] = a[a[q[i]]];
  }
  for (int i = 1; i <= n; i++) q[i] = qs[i];
  if (k % 2)
    for (int i = 1; i <= n; i++) q[i] = r[q[i]];
  for (int i = k % 2; i <= k; i += 2) {
    bool f = false;
    for (int i = 1; i <= n; i++)
      if (b[i] != q[i]) f = true;
    if (!f) return true;
    for (int i = 1; i <= n; i++) q[i] = r[r[q[i]]];
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), r[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) continue;
    s++;
    int d = 1, x = a[i];
    while (x != i) d++, x = a[x];
    if (d > 2) {
      g++;
      if (i != b[i]) t = true;
    }
    if (i == b[i]) s--;
  }
  if (!s)
    printf("NO");
  else if (t) {
    for (int i = 1; i <= n; i++) q1[i] = i;
    if (work(k, q1))
      printf("YES");
    else
      printf("NO");
  } else if (g) {
    for (int i = 1; i <= n; i++) q1[i] = a[i], q2[i] = r[i];
    if (work(k - 1, q1) || work(k - 1, q2))
      printf("YES");
    else
      printf("NO");
  } else {
    int s = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == b[i]) s++;
    if (s == n && k == 1)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
