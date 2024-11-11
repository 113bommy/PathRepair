#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, j, k, l, m, curr, lo, mid, hi, maxi;
  map<long long int, long long int> mp;
  cin >> n >> k;
  long long int A[n + 5], sum[n + 5], B[n + 5];
  for (i = 0; i < n; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(A, A + n);
  sort(B, B + n);
  reverse(B, B + n);
  sum[0] = B[0];
  for (i = 1; i < n; i++) sum[i] = sum[i - 1] + B[i];
  reverse(sum, sum + n);
  long long int ans1 = 0, ans2 = 0, temp1 = 0, temp2 = 0;
  for (i = n - 1; i > 0; i--) {
    lo = 0, hi = i - 1;
    temp1 = 0;
    mid = (lo + hi) / 2;
    while (lo <= hi && i >= mid) {
      mid = (lo + hi) / 2;
      l = sum[mid] - sum[i] + k;
      if (l >= (A[i] * (i - mid))) {
        temp1 = i - mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
      mid = (lo + hi) / 2;
    }
    if (temp1 >= ans1) {
      ans1 = temp1;
      ans2 = A[i];
    }
  }
  cout << ans1 + 1 << " " << ans2;
}
