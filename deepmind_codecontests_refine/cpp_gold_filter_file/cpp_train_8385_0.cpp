#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001], p[100001];
bool des[100001];
int l[100001], r[100001];
long long ans[100001];
long long sum[100001];
bool judge(int p) {
  if (p < 1 || p > n) return true;
  if (des[p]) return true;
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), sum[i] = sum[i - 1] + (long long)(a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) des[i] = true, l[i] = r[i] = 0;
  ans[n] = 0;
  for (int i = n; i >= 2; i--) {
    des[p[i]] = false;
    if (judge(p[i] - 1) && judge(p[i] + 1)) {
      l[p[i]] = r[p[i]] = p[i];
      ans[i - 1] = max(ans[i], (long long)(a[p[i]]));
    } else if (judge(p[i] - 1)) {
      r[p[i]] = r[p[i] + 1];
      l[r[p[i]]] = p[i];
      ans[i - 1] = max(ans[i], sum[r[p[i]]] - sum[p[i] - 1]);
    } else if (judge(p[i] + 1)) {
      l[p[i]] = l[p[i] - 1];
      r[l[p[i]]] = p[i];
      ans[i - 1] = max(ans[i], sum[p[i]] - sum[l[p[i]] - 1]);
    } else {
      r[l[p[i] - 1]] = r[p[i] + 1];
      l[r[p[i] + 1]] = l[p[i] - 1];
      ans[i - 1] = max(ans[i], sum[r[p[i] + 1]] - sum[l[p[i] - 1] - 1]);
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
  return 0;
}
