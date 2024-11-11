#include <bits/stdc++.h>
using namespace std;
int n, m, res, res2;
int a[1000010], b[1000010];
long long cnt[50], need[50], tcnt[50];
inline bool check(int x) {
  for (int i = 0; i < 30; i++) tcnt[i] = cnt[i];
  int now = x;
  for (int i = 29; i >= 0 && now; i--) {
    if (i < b[now]) return 0;
    for (;;) {
      if (tcnt[i]) {
        tcnt[i]--;
        for (int k = 0; k < i; k++)
          if ((1 << k) & ((1 << i) - (1 << b[now]))) tcnt[k]++;
        --now;
      } else
        break;
    }
  }
  if (now) return 1;
  return 0;
}
int main(int argc, const char* argv[]) {
  scanf("%d%d", &n, &m);
  memset(cnt, 0, sizeof(cnt));
  memset(need, 0, sizeof(need));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j < 30; j++)
      if (a[i] & (1 << j)) cnt[j]++;
  }
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(b + 1, b + 1 + m);
  int head = 0, tail = m + 1, mid;
  while (head + 1 < tail) {
    mid = head + tail >> 1;
    if (check(mid))
      head = mid;
    else
      tail = mid;
  }
  printf("%d\n", head);
  return 0;
}
