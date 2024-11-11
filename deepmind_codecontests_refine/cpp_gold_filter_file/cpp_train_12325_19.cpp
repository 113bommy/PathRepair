#include <bits/stdc++.h>
int a[10001];
int rem[1000001];
int f[1000001];
bool cmp(const int &a, const int &b) {
  if (a >= b) return false;
  return true;
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  std::sort(a, a + n, cmp);
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) rem[a[i] - a[j]]++;
  int m = -1;
  for (int i = n - k; i < 1000001; i++) {
    int temp = 0;
    int now = i;
    bool flag = true;
    while (now <= a[n - 1]) {
      temp += rem[now];
      now += i;
      if (temp > k * (k + 1) / 2) {
        flag = false;
        break;
      }
    }
    if (flag) {
      temp = 0;
      memset(f, 0, sizeof(f));
      for (int j = 0; j < n; j++)
        if (f[a[j] % i])
          temp++;
        else
          f[a[j] % i] = 1;
      if (temp <= k) m = i;
    }
    if (m != -1) break;
  }
  printf("%d\n", m);
}
