#include <bits/stdc++.h>
using namespace std;
int a[100005];
long long b[100005], s, mx;
bool t;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t)
      s += a[i];
    else
      b[i] = a[i];
    if (i) b[i] += b[i - 1];
  }
  mx = b[k - 1];
  for (int i = 1; i < n - k; i++) mx = max(mx, b[i + k - 1] - b[i - 1]);
  cout << s + mx;
  return 0;
}
