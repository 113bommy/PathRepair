#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  long long l;
  cin >> n >> m >> l;
  long hair[n];
  bool lc = false;
  long cnt = 0;
  for (long i = 0; i < n; i++) {
    cin >> hair[i];
    if (hair[i] > l && !lc) {
      cnt += 1;
      lc = true;
    } else if (hair[i] <= l && lc) {
      lc = false;
    }
  }
  for (long i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (k == 0) {
      cout << cnt << endl;
    } else {
      long long p, d;
      cin >> p >> d;
      p--;
      if (hair[p] <= l) {
        if (hair[p] + d > l) {
          hair[p] = l + 1;
        } else {
          hair[p] += d;
        }
        if (p - 1 == -1 || p + 1 == n) {
          if (hair[p] > l) {
            cnt++;
          }
        } else if (p - 1 == -1) {
          if (hair[p + 1] <= l && hair[p] > l) {
            cnt++;
          }
        } else if (p + 1 == n) {
          if (hair[p - 1] <= l && hair[p] > l) {
            cnt++;
          }
        } else {
          if (hair[p + 1] > l && hair[p] > l && hair[p - 1] > l) {
            cnt--;
          } else if (hair[p] > l && hair[p - 1] <= l && hair[p + 1] <= l) {
            cnt++;
          }
        }
      }
    }
  }
  return 0;
}
