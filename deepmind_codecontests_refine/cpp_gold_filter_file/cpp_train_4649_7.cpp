#include <bits/stdc++.h>
using namespace std;
int a[300005], len[300005], n;
int ord[300005], m;
long long dp[300005];
void oper(int k) {
  int val = min(a[k], a[k + 1]);
  if (val) {
    ord[m++] = k;
    a[k] -= val, a[k + 1] -= val;
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    long long f = (i > 1 ? dp[i - 2] : 0) + a[i];
    long long s = (i > 2 ? dp[i - 3] : 0) + max(a[i], a[i - 1]);
    dp[i] = min(f, s);
    len[i] = 2 - (dp[i] == f);
  }
  long long ans = min(dp[n], dp[n - 1]);
  vector<int> vec;
  for (int pt = n - (dp[n - 1] == ans); pt > 0; pt -= len[pt] + 1)
    vec.push_back(pt);
  for (int i = 0; i < vec.size(); i++) {
    int k = vec[i];
    if (len[k] == 1) {
      oper(k);
      if (a[k] > 0) oper(k - 1);
    } else {
      oper(k - 1);
      if (a[k] > 0) oper(k);
      if (a[k - 1] > 0) oper(k - 2);
    }
  }
  printf("%d\n", m);
  for (int i = 0; i < m; i++) printf("%d\n", ord[i]);
  return 0;
}
