#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n;
  cin >> m >> n;
  long long p[n];
  long long x;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    fflush(stdout);
    cin >> x;
    if (x == 0 || x == -2) {
      flag = 1;
      break;
    }
    if (x == 1)
      p[i] = 1;
    else
      p[i] = 0;
  }
  if (!flag) {
    long long lo = 1;
    long long hi = m;
    int i = 0;
    while (1) {
      long long mid = (lo + hi) / 2;
      cout << mid << endl;
      fflush(stdout);
      cin >> x;
      if (x == 0 || x == -2) break;
      if (x == 1) {
        if (p[i])
          lo = mid + 1;
        else
          hi = max(lo, mid - 1);
      } else {
        if (p[i])
          hi = max(lo, mid - 1);
        else
          lo = mid + 1;
      }
      ++i;
    }
  }
}
