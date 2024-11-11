#include <bits/stdc++.h>
using namespace std;
int k[5000], a[5000], x[5000], y[5000], m[5000], pos[5000];
pair<int, int> ans[200000], l[200000];
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%d", &k[i], &a[i], &x[i], &y[i], &m[i]);
    pos[i] = 0;
    sum += k[i];
  }
  int tot = 0, bad = 0;
  while (true) {
    bool flag = true;
    for (int i = 0; i < n; i++)
      if (pos[i] < k[i]) {
        flag = false;
        break;
      }
    if (flag) break;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (pos[i] == k[i]) continue;
      while (pos[i] < k[i]) {
        if (sum <= 200000) l[cnt++] = make_pair(a[i], i);
        pos[i]++;
        if (pos[i] == k[i]) break;
        int last = a[i];
        a[i] = (int)(((long long)a[i] * x[i] + y[i]) % m[i]);
        if (a[i] < last) break;
      }
    }
    if (sum <= 200000) {
      sort(l, l + cnt);
      for (int i = 0; i < cnt; i++) ans[tot++] = l[i];
    }
    bad++;
  }
  bad--;
  printf("%d\n", bad);
  if (sum <= 200000) {
    for (int i = 0; i < tot; i++)
      printf("%d %d\n", ans[i].first, ans[i].second + 1);
  }
  return 0;
}
