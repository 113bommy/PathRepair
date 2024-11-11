#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int T, n, k;
int A[maxn], B[maxn];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      if (i & 1)
        sum2 += A[i];
      else
        sum1 += A[i];
    }
    int cnt1 = 0;
    for (int i = 0; i < n - 1; i += 2) B[cnt1++] = A[i + 1] - A[i];
    long long sum = 0, res = 0;
    for (int i = 0; i < cnt1; i++) {
      if (sum < 0) sum = 0;
      sum += B[i];
      if (sum > res) res = sum;
    }
    long long ans = sum1;
    if (res > 0) ans = max(ans, sum1 + res);
    int cnt2 = 0;
    for (int i = 1; i < n - 1; i += 2) B[cnt2++] = A[i] - A[i + 1];
    sum = 0, res = 0;
    for (int i = 0; i < cnt2; i++) {
      if (sum < 0) sum = 0;
      sum += B[i];
      if (sum > res) res = sum;
    }
    if (res > 0) ans = max(ans, sum1 + res);
    cout << ans << endl;
  }
}
