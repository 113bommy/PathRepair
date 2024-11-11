#include <bits/stdc++.h>
int main() {
  int last[100000], cur[100000], cnt[100000], left[100000], right[100000],
      nx[100000];
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) last[i] = -1;
  int max = -1;
  for (int i = 0; i < n; i++) {
    int c;
    scanf("%d", &c);
    c--;
    if (last[c] != -1) {
      nx[last[c]] = i;
      cnt[c]++;
      cur[c] += i - last[c] - 1;
      right[c] = i;
      while (cur[c] > k) {
        cur[c] -= nx[left[c]] - left[c] - 1;
        left[c] = nx[left[c]];
        cnt[c]--;
      }
    } else {
      left[c] = right[c] = i;
      cur[c] = 0;
      cnt[c] = 1;
    }
    if (cnt[c] > max) max = cnt[c];
    last[c] = i;
  }
  printf("%d\n", max);
  return 0;
}
