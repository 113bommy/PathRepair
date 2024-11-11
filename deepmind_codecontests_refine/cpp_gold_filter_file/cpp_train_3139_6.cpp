#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int H, n;
  cin >> H >> n;
  vector<long long int> a(n);
  long long int sum = 0;
  long long int gap = 0;
  long long int h = H;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum -= a[i];
    h += a[i];
    if (h <= 0) {
      cout << i + 1 << endl;
      return 0;
    }
    gap = max(gap, sum);
  }
  if (sum <= 0) {
    cout << -1;
    return 0;
  }
  long long int whole = (H - gap) / sum;
  H -= whole * sum;
  long long int result = whole * n;
  for (int i = 0;; ++i) {
    H += a[i % n];
    result++;
    if (H <= 0) {
      cout << result;
      return 0;
    }
  }
}
