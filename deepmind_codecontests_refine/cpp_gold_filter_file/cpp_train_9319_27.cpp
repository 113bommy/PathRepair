#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 100;
int n;
long long a[maxn], b[maxn];
long long pa[maxn], pb[maxn];
void input() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
}
void solve() {
  long long res = 0;
  for (long long l = 0; l < n; l++) {
    for (long long r = l; r <= n - 1; r++) {
      long long sum1 = a[l], sum2 = b[l];
      for (long long i = l + 1; i <= r; i++) {
        sum1 |= a[i];
        sum2 |= b[i];
      }
      res = max(sum1 + sum2, res);
    }
  }
  cout << res << endl;
}
int main() {
  input();
  solve();
  return 0;
}
