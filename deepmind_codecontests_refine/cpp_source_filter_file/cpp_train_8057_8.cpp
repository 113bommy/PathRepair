#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
long long a[N], b[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  long long l = -1, r = 1e10;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (j >= m) break;
      while (a[i] == b[j]) {
        j++;
        if (j >= m) break;
      }
      if (j >= m) break;
      if (b[j] > a[i]) {
        while (b[j] <= a[i] + mid) {
          j++;
          if (j >= m) break;
        }
        if (j >= m) break;
        continue;
      }
      if (mid < a[i] - b[j]) break;
      long long x = max(mid - 2 * (a[i] - b[j]), (mid - (a[i] - b[j])) / 2);
      if (x <= 0) x = 0;
      while (b[j] <= a[i] + x) {
        j++;
        if (j >= m) break;
      }
      if (j >= m) break;
    }
    if (j >= m) {
      r = mid;
      continue;
    }
    l = mid;
  }
  cout << r;
}
