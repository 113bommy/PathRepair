#include <bits/stdc++.h>
const int maxn = 200005;
int p[maxn], in[maxn], id[maxn];
int inside[maxn], inter[maxn];
int n;
int lowbit(int n) { return (n & (-n)); }
void update(int n) {
  int i;
  for (i = n; i < maxn; i += lowbit(i)) in[i]++;
}
int query(int n) {
  int i, sum = 0;
  for (i = n; i > 0; i -= lowbit(i)) sum += in[i];
  return sum;
}
int main() {
  int i, a, b;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    p[a] = b;
    p[b] = a;
    id[a] = i;
    id[b] = i;
  }
  memset(in, 0, sizeof(in));
  for (i = 1; i <= 2 * n; i++) {
    if (i > p[i]) {
      inside[id[i]] = query(i) - query(p[i]);
      update(p[i]);
      inter[id[i]] = i - p[i] - 1 - 2 * inside[id[i]];
    }
  }
  long long sum = (long long)n * (n - 1) * (n - 2) / 6, temp = 0;
  for (i = 0; i < n; i++) {
    sum -= (long long)inside[i] * (n - inside[i] - inter[i] - 1);
    temp += (long long)(inter[i] * (n - inter[i] - 1));
  }
  printf("%I64d\n", sum - temp / 2);
  return 0;
}
