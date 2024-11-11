#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const int maxn = 2e5 + 7;
int s[maxn];
long long x[maxn];
long long y[maxn];
long long sum[maxn];
long long t[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    int index = lower_bound(x + 1, x + 1 + n, y[i]) - x;
    t[i] = ((sum[i - 1] - sum[index - 1]) % M + x[i]) % M - y[i];
    t[i] %= M;
    sum[i] = sum[i - 1] + t[i];
    sum[i] %= M;
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i]) {
      res += t[i];
      res %= M;
    }
  }
  res += x[n] + 1;
  cout << (res + M) % M << '\n';
}
