#include <bits/stdc++.h>
using namespace std;
struct lwn {
  int value, key, id;
} sta[300050];
int cnt[1000050];
int s[100050];
int maxa[100050];
int a[100050], m, i, j, k, n;
long long ans;
void solve(int l, int r) {
  if (l == r) return;
  solve(l, ((l + r) >> 1));
  solve(((l + r) >> 1) + 1, r);
  s[((l + r) >> 1)] = a[((l + r) >> 1)] % m;
  maxa[((l + r) >> 1)] = a[((l + r) >> 1)];
  s[((l + r) >> 1) + 1] = a[((l + r) >> 1) + 1] % m;
  maxa[((l + r) >> 1) + 1] = a[((l + r) >> 1) + 1];
  for (i = ((l + r) >> 1) - 1; i >= l; i--) {
    s[i] = (s[i + 1] + a[i]) % m;
    maxa[i] = max(maxa[i + 1], a[i]);
  }
  for (i = ((l + r) >> 1) + 2; i <= r; i++) {
    s[i] = (s[i - 1] + a[i]) % m;
    maxa[i] = max(maxa[i - 1], a[i]);
  }
  k = 0;
  for (i = ((l + r) >> 1), j = ((l + r) >> 1) + 1; i >= l && j <= r;) {
    for (; i >= l && maxa[i] <= maxa[j]; i--) {
      sta[++k].key = maxa[i];
      sta[k].value = s[i];
      sta[k].id = i;
    }
    for (; j <= r && maxa[i] > maxa[j]; j++) {
      sta[++k].key = maxa[j];
      sta[k].value = s[j];
      sta[k].id = j;
    }
  }
  for (; i >= l; i--) {
    sta[++k].key = maxa[i];
    sta[k].value = s[i];
    sta[k].id = i;
  }
  for (; j <= r; j++) {
    sta[++k].key = maxa[j];
    sta[k].value = s[j];
    sta[k].id = j;
  }
  for (i = 1; i <= k; i++)
    if (sta[i].id > ((l + r) >> 1))
      cnt[(m - sta[i].value) % m]++;
    else
      ans += cnt[(m + sta[i].value - sta[i].key % m) % m];
  for (i = 1; i <= k; i++)
    if (sta[i].id > ((l + r) >> 1)) cnt[(m - sta[i].value) % m]--;
  for (i = k; i >= 1; i--)
    if (sta[i].id > ((l + r) >> 1))
      cnt[(m + sta[i].key - sta[i].value) % m]++;
    else
      ans += cnt[sta[i].value % m];
  for (i = k; i >= 1; i--)
    if (sta[i].id > ((l + r) >> 1)) cnt[(m + sta[i].key - sta[i].value) % m]--;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
