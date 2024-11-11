#include <bits/stdc++.h>
using namespace std;
stack<long long int> s;
long long int leftdp[300000][20], rightdp[300000][20], twopow[20], x[300001],
    logval[300001];
int main() {
  long long int n, a, i, j, k, l, len, val, val1, val2, ans = 0;
  twopow[0] = 1;
  for (i = 1; i <= 19; i++) twopow[i] = 2 * twopow[i - 1];
  for (i = 0; i < 19; i++) x[twopow[i]] = twopow[i];
  for (i = 0; i < 19; i++) logval[twopow[i]] = i;
  for (i = 3; i <= 300000; i++) {
    if (x[i] == 0) x[i] = x[i - 1];
    if (x[i] == 0) logval[i] = logval[i - 1];
  }
  scanf("%lld %lld", &n, &a);
  long long int c[n], c1[n], c2[n], d[n], diff[n - 1], left[n - 1],
      right[n - 1];
  for (i = 0; i < n; i++) scanf("%lld %lld", &d[i], &c[i]);
  for (i = 0; i < n - 1; i++) diff[i] = d[i + 1] - d[i];
  s.push(0);
  for (i = 1; i < n - 1; i++) {
    if (diff[i] > diff[s.top()]) {
      while (!s.empty() && diff[i] > diff[s.top()]) {
        right[s.top()] = i - 1;
        s.pop();
      }
    }
    s.push(i);
  }
  while (!s.empty()) {
    right[s.top()] = n - 2;
    s.pop();
  }
  if (n >= 2) s.push(n - 2);
  for (i = n - 3; i >= 0; i--) {
    if (diff[i] >= diff[s.top()]) {
      while (!s.empty() && diff[i] > diff[s.top()]) {
        left[s.top()] = i + 1;
        s.pop();
      }
    }
    s.push(i);
  }
  while (!s.empty()) {
    left[s.top()] = 0;
    s.pop();
  }
  for (i = 0; i < n; i++) c[i] = a - c[i];
  for (i = 0; i < n; i++) ans = max(ans, c[i]);
  if (ans == 0) {
    printf("0");
    return 0;
  }
  for (i = 0; i < n; i++) {
    c1[i] = c[i];
    c2[i] = c[i];
  }
  for (i = 1; i < n; i++) c1[i] += c1[i - 1];
  for (i = n - 2; i >= 0; i--) c2[i] += c2[i + 1];
  for (i = n - 1; i >= 0; i--) {
    rightdp[i][0] = c1[i];
    for (j = 1; i + twopow[j] <= n; j++)
      rightdp[i][j] = max(rightdp[i][j - 1], rightdp[i + twopow[j - 1]][j - 1]);
  }
  for (i = 0; i < n; i++) {
    leftdp[i][0] = c2[i];
    for (j = 1; i - twopow[j] >= -1; j++)
      leftdp[i][j] = max(leftdp[i][j - 1], leftdp[i - twopow[j - 1]][j - 1]);
  }
  for (i = 0; i < n - 1; i++) {
    len = right[i] - i + 1;
    val1 = max(rightdp[i + 1][logval[len]],
               rightdp[i + 1 + (len - x[len])][logval[len]]);
    len = i - left[i] + 1;
    val2 = max(leftdp[i][logval[len]], leftdp[i - (len - x[len])][logval[len]]);
    val = max(val1 - c1[i], c[i + 1]);
    val += max(val2 - c2[i + 1], c[i]);
    val -= diff[i] * diff[i];
    ans = max(ans, val);
  }
  printf("%lld", ans);
  return 0;
}
