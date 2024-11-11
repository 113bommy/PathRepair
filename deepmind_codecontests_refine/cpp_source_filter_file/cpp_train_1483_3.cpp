#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long sum = 0, p[n], l[n], mx = 0;
  for (int i = 0; i < m; i++) {
    cin >> l[i];
    sum += l[i];
    mx = max(mx, l[i]);
  }
  if (sum < n) {
    cout << -1;
    return 0;
  }
  p[0] = 1;
  long long cov = l[0];
  sum -= l[0];
  for (int i = 1; i < m; i++) {
    int x;
    if (sum >= n - p[i - 1]) {
      if (p[i - 1] + l[i] > n) {
        cout << -1;
        return 0;
      }
      x = p[i - 1] + 1;
    } else {
      x = n - l[i] + 1;
      if (x > cov + 1) {
        x = cov + 1;
      }
    }
    p[i] = x;
    cov = max(cov, x - 1 + l[i]);
    sum -= l[i];
  }
  if (cov < n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    cout << p[i] << ' ';
  }
  return 0;
}
