#include <bits/stdc++.h>
using namespace std;
int n, u, r;
long long a[31], b[31], k[31], p[31];
long long Get_Val(long long arr[]) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (long long)k[i] * arr[i];
  }
  return ans;
}
long long solve(string cur, int leftk, long long arr[]) {
  long long ans = LLONG_MIN;
  if (leftk == 0) {
    return Get_Val(arr);
  }
  if (!(leftk & 1)) {
    ans = max(ans, Get_Val(arr));
  }
  if (cur.back() == '0') {
    long long tmp[31];
    for (int i = 1; i <= n; i++) tmp[i] = arr[p[i]] + r;
    ans = max(ans, solve(cur + '1', leftk - 1, tmp));
  } else {
    long long tmp[31];
    for (int i = 1; i <= n; i++) tmp[i] = arr[i] ^ b[i];
    ans = max(ans, solve(cur + '0', leftk - 1, tmp));
    for (int i = 1; i <= n; i++) tmp[i] = arr[p[i]] + r;
    ans = max(ans, solve(cur + '1', leftk - 1, tmp));
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &u, &r);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &k[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &p[i]);
  printf("%I64d\n", solve("", u, a));
  return 0;
}
