#include <bits/stdc++.h>
using namespace std;
long long ar[300005];
long long n, m;
bool chk(long long k) {
  long long lst = ar[0];
  for (int i = 1; i < n; i++) {
    if (ar[i] < lst) {
      if (lst - ar[i] > k) {
        return false;
      }
    } else {
      if (m - ar[i] + lst <= k) {
        continue;
      } else {
        lst = ar[i];
      }
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  long long lo = 0, hi = m, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (chk(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << endl;
  return 0;
}
