#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m;
  cin >> m;
  long long low = 1;
  long long high = 80000000000000000L;
  long long ans = 800000000000000001L;
  while (low <= high) {
    long long mid = (low + high) / 2;
    long long nway = 0;
    for (long long i = 2; i <= 200002; i++) {
      long long val = i * i;
      val = val * i;
      nway = nway + (mid / val);
      if (mid / val < 1) break;
    }
    if (nway == m) ans = min(ans, mid);
    if (nway >= m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (ans <= 80000000000000000L) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
