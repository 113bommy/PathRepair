#include <bits/stdc++.h>
using namespace std;
const int infint = INT_MAX;
const long long infll = LLONG_MAX;
const int MAX = 1e5 + 100;
long long arr[MAX], sum[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(sum, 0, sizeof(sum));
  memset(arr, 0, sizeof(arr));
  long long n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  for (int i = 1; i < n + 1; i++) cin >> arr[i];
  for (int i = 1; i < n + 1; i++) sum[i] += sum[i - 1] + arr[i];
  long long ans = 1e12;
  for (int i = 0; i < n + 1; i++) {
    long long inter1 = 0, inter2 = 0;
    inter1 = l * sum[i] + (sum[n] - sum[i]) * r;
    if (i > n - i) {
      inter1 += max(0LL, (2 * i - n - 1)) * ql;
    } else if (i < n - i) {
      inter1 += max(0LL, (n - 2 * i - 1)) * qr;
    }
    ans = min(ans, inter1);
  }
  cout << ans;
  return 0;
}
