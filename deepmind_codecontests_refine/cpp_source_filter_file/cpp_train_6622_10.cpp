#include <bits/stdc++.h>
using namespace std;
void _() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  _();
  long long n, k;
  cin >> n >> k;
  long long a[n], sum = 0;
  for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
  if (sum < k) return cout << -1, 0;
  long long l = -1, r = sum;
  while (l + 1 < r) {
    long long mid = (r - l) / 2 + l, x = k;
    for (int i = 0; i < n; i++) {
      if (mid >= a[i])
        x -= mid;
      else
        x -= mid + 1;
    }
    if (x > 0)
      l = mid;
    else
      r = mid;
  }
  int id = 0;
  for (int i = 0; i < n; i++) {
    long long mn = min(r, a[i]);
    a[i] -= mn;
    k -= mn;
  }
  for (int i = 0; i < n && k; i++) {
    id = (i + 1) % n;
    if (a[i]) {
      a[i]--;
      k--;
    }
  }
  for (int i = id; i < n; i++)
    if (a[i]) cout << i + 1 << " ";
  for (int i = 0; i < id; i++)
    if (a[i]) cout << i + 1 << " ";
}
