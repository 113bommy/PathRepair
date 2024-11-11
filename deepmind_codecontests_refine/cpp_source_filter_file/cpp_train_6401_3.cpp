#include <bits/stdc++.h>
using namespace std;
long long a[400000];
long long ans = 0, k;
long long q[1010000];
void f(int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  f(l, mid), f(mid + 1, r);
  long long sum = 0, mx = 0, sum2 = 0;
  long long uk = mid, Sum = 0;
  vector<int> h;
  for (int i = mid; i >= l; i--) {
    mx = max(mx, a[i]);
    Sum += a[i];
    sum = Sum - mx;
    sum = sum % k;
    while (uk + 1 <= r and a[uk + 1] <= mx) {
      sum2 += a[uk + 1];
      uk++;
      if (q[sum2 % k] == 0) h.push_back(sum2 % k);
      q[sum2 % k]++;
    }
    ans += q[(k - sum) % k];
  }
  for (int i = 0; i < h.size(); i++) q[h[i]] = 0;
  h.clear();
  mx = 0;
  sum = 0;
  Sum = sum2;
  for (int i = mid + 1, g = mid + 1; i <= r; i++) {
    mx = max(a[i], mx);
    Sum += a[i];
    sum2 = Sum - mx;
    sum2 = sum2 % k;
    while (g - 1 >= l and a[g - 1] < mx) {
      sum += a[g - 1];
      g--;
      if (q[sum % k] == 0) h.push_back(sum % k);
      q[sum % k]++;
    }
    ans += q[(k - sum2) % k];
  }
  for (int i = 0; i < h.size(); i++) q[h[i]] = 0;
  h.clear();
}
void solve() {
  int n;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  f(1, n);
  cout << ans;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
