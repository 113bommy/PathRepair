#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 1e5 + 5;
const long long INF = 1e9 + 5;
const long long MOD = 1e9 + 7;
const double PI = 3.141592653589793116;
int n, k;
long long ans, yt, a[N];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  long long sum = 0, x = 0, y = 0;
  for (int i = 0; i < n - 1; i++) {
    sum = a[i] + yt;
    x = sum / k;
    y = x * k;
    if (y >= yt) {
      ans += x;
      yt = sum - y;
    } else {
      ans += (sum + k - 1) / k;
      yt = 0;
    }
  }
  ans += (a[n - 1] + yt + k - 1) / k;
  printf("%lld", ans);
}
