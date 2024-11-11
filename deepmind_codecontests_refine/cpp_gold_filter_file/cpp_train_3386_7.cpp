#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const long long inf = 1000000;
int n, s[maxn], top = 0;
long long a[maxn], sum[maxn];
int now;
bool judge(int x) {
  int j = s[x], i = s[x + 1];
  return sum[j] - sum[i] < a[now] * (j - i);
}
int BS(int l, int r) {
  if (r - l <= 1) {
    if (judge(l)) return l;
    return r;
  }
  int m = (l + r) / 2;
  if (judge(m)) return BS(l, m);
  return BS(m + 1, r);
}
bool judge1(int x) {
  int i = s[x - 1], j = s[x];
  return sum[j - 1] - sum[i - 1] < a[now] * (j - i);
}
int BS1(int l, int r) {
  if (r - l <= 1) {
    if (judge1(r)) return r;
    return l;
  }
  int m = (l + r) / 2;
  if (judge1(m)) return BS1(m, r);
  return BS1(l, m - 1);
}
int main() {
  cin >> n;
  long long S = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    a[i] += inf;
    S += a[i] * i;
    sum[i] = sum[i - 1] + a[i];
  }
  long long ret = 0;
  s[top++] = n;
  for (int i = n - 1; i >= 1; i--) {
    now = i;
    int k = s[BS(0, top - 2)], k2 = s[top - 1];
    ret = max(ret, sum[i] - sum[k] + a[i] * (k - i));
    ret = max(ret, sum[i] - sum[k2] + a[i] * (k2 - i));
    while (top >= 2 &&
           (sum[s[top - 2]] - sum[s[top - 1]]) * (s[top - 1] - i) <=
               (sum[s[top - 1]] - sum[i]) * (s[top - 2] - s[top - 1]))
      top--;
    s[top++] = i;
  }
  top = 0;
  s[top++] = 1;
  for (int i = 2; i <= n; i++) {
    now = i;
    int k = s[BS1(1, top - 1)], k2 = s[0];
    ret = max(ret, sum[i - 1] - sum[k - 1] - a[i] * (i - k));
    ret = max(ret, sum[i - 1] - sum[k2 - 1] - a[i] * (i - k2));
    while (top >= 2 &&
           (sum[i - 1] - sum[s[top - 1] - 1]) * (s[top - 1] - s[top - 2]) <=
               (sum[s[top - 1] - 1] - sum[s[top - 2] - 1]) * (i - s[top - 1]))
      top--;
    s[top++] = i;
  }
  cout << S + ret - inf * (n * (n + 1LL)) / 2 << endl;
  return 0;
}
