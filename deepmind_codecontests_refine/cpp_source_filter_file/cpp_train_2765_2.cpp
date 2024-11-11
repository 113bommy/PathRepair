#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 123;
int n;
int a[maxn];
long long sum[maxn];
void ReadData() {
  scanf("%d", &n);
  for (int i = 1, _b = n; i <= _b; ++i) scanf("%d", &a[i]);
  reverse(a + 1, a + 1 + n);
  for (int i = 1, _b = n; i <= _b; ++i) sum[i] = sum[i - 1] + a[i];
}
long long f[maxn], g[maxn];
void minimize(long long &a, long long b) {
  if (a > b) a = b;
}
void maximize(long long &a, long long b) {
  if (a < b) a = b;
}
void Process() {
  f[1] = sum[n];
  g[1] = -sum[n];
  long long mnF = f[1] + sum[1], mxG = g[1] - sum[1];
  for (int i = 2, _b = n; i <= _b; ++i) {
    f[i] = mxG + sum[n];
    g[i] = mnF - sum[n];
    g[i] = min(g[i], -sum[n]);
    f[i] = max(f[i], sum[n]);
    maximize(mxG, g[i] - sum[i]);
    minimize(mnF, f[i] + sum[i]);
  }
  cout << f[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
  return 0;
}
