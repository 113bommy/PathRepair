#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int N = 1010;
int n, k, m;
int a[N], b[N];
long long max(long long x, long long y) { return x > y ? x : y; }
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long resa = 0;
    long long resb = 0;
    for (int j = i; j <= n; j++) {
      resa |= a[j];
      resb |= b[j];
      ans = max(ans, resa + resb);
    }
  }
  cout << ans;
  return 0;
}
