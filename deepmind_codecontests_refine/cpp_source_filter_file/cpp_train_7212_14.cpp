#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, pos = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') pos = 0;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
  return pos ? x : -x;
}
const int N = 3e3 + 200;
int n, k, t[N];
vector<long long> a[N];
long long f[N];
long long c[N];
long long an = 0;
void calc(int now) {
  long long ans = 0, rec = 0;
  ans = max(f[k], ans);
  for (int j = 1; j <= t[now]; j++)
    rec += a[now][j], ans = max(f[k - j] + rec, ans);
  an = max(an, ans);
}
void solve(int l, int r) {
  if (l == r) {
    calc(l);
    return;
  }
  int mid = (l + r) >> 1;
  long long g[N];
  for (int i = 0; i <= k; i++) g[i] = f[i];
  for (int i = mid + 1; i <= r; i++) {
    for (int j = k - t[i]; j >= 0; j--) {
      f[j + t[i]] = max(f[j + t[i]], f[j] + c[i]);
    }
  }
  solve(l, mid);
  for (int i = 0; i <= k; i++) f[i] = g[i];
  for (int i = l; i <= mid; i++) {
    for (int j = k - t[i]; j >= 0; j--) {
      f[j + t[i]] = max(f[j + t[i]], f[j] + c[i]);
    }
  }
  solve(mid + 1, r);
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    t[i] = read();
    a[i].push_back(0);
    for (int j = 1; j <= t[i]; j++) a[i].push_back(read()), c[i] += a[i][j];
  }
  solve(1, n);
  printf("%lld\n", an);
  return 0;
}
