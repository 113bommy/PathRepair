#include <bits/stdc++.h>
using namespace std;
int n, t, cnt;
int nums[40];
long long a[100];
int ans[40];
void divide(long long k) {
  memset(nums, 0, sizeof nums);
  cnt = 0;
  while (k) {
    nums[++cnt] = k % 2;
    k >>= 1;
  }
}
int main() {
  cin >> t;
  while (t--) {
    memset(ans, 0, sizeof ans);
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      divide(a[i]);
      for (int i = 1; i <= 31; i++) {
        if (!nums[i]) ans[i] = 1;
      }
    }
    long long op = 0;
    for (int i = 31; i >= 1; i--) {
      op *= 2;
      if (!ans[i]) op++;
    }
    cout << op << '\n';
  }
  return 0;
}
