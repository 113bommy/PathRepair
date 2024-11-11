#include <bits/stdc++.h>
using namespace std;
int A[100004];
int B[100004];
int count_inv(int b, int e) {
  if (b == e) return 0;
  int h = (b + e) >> 1;
  int ans = count_inv(b, h) + count_inv(h + 1, e);
  int l = b, r = h + 1;
  for (int i = b; i <= e; i++) {
    if (r > e || (l <= h && A[l] <= A[r])) {
      B[i] = A[l++];
    } else {
      B[i] = A[r++];
      ans += h + 1 - l;
    }
  }
  for (int i = b; i <= e; i++) {
    A[i] = B[i];
  }
  return ans;
}
int main() {
  ios ::sync_with_stdio(0);
  int n, k;
  while (cin >> n >> k) {
    long long ans = 0;
    for (int i = 0; i < k && i < n - 1 - i; i++) {
      ans += 2 * (n - 2 - 2 * i) + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
