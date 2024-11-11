#include <bits/stdc++.h>
using namespace std;
int a[101000];
long long sum[101000];
int n;
int l, r, ql, qr;
long long ans = 0x3f3f3f3f3f3f3f3f;
int main() {
  cin >> n >> l >> r >> ql >> qr;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i < n / 2; i++)
    ans = min(ans, sum[i] * l + (sum[n] - sum[i]) * r + qr * (n - i - i - 1));
  ans = min(ans, sum[n / 2] * l + (sum[n] - sum[n / 2]) * r);
  for (int i = n / 2 + 1; i <= n; i++)
    ans = min(ans, sum[i] * l + (sum[n] - sum[i]) * r + ql * (i - (n - i) - 1));
  cout << ans << endl;
}
