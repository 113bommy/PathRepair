#include <bits/stdc++.h>
const int MAXN = 4001;
int n, v[MAXN], p[MAXN], d[MAXN], state[MAXN], q[MAXN], answer[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", v + i, d + i, p + i);
    state[i] = 1;
  }
  int counter = 0;
  for (int i = 1; i <= n; i++) {
    if (state[i] == 2) continue;
    answer[++counter] = i;
    int left = 0, right = 0;
    for (int j = i + 1, cnt = 0; j <= n && cnt <= v[i]; j++) {
      if (state[j] == 2) continue;
      p[j] -= v[i] - cnt;
      cnt++;
      if (p[j] < 0) {
        q[++right] = j;
        state[j] = 2;
      }
    }
    while (left < right) {
      left++;
      for (int j = q[left] + 1; j <= n; j++) {
        if (state[j] == 2) continue;
        p[j] -= d[q[left]];
        if (p[j] < 0) {
          q[++right] = j;
          state[j] = 2;
        }
      }
    }
  }
  printf("%d\n", counter);
  for (int i = 1; i <= counter; i++)
    printf("%d%c", answer[i], " \n"[i == counter]);
  return 0;
}
