#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int fans = 1;
long long getnum(long long x) {
  long long fx, fy;
  if (x >= (n - k + 1)) {
    fx = (n - k + 1 + 1) * (n - k + 1) / 2 + (x - (n - k + 1)) * (n - k + 1);
  } else {
    fx = (x - 1 + 1) * (x - 1) / 2 + (n - k + 1);
  }
  if (x >= k) {
    fy = (k + 1) * k / 2 + (x - k) * k;
  } else {
    fy = (x - 1 + 1) * (x - 1) / 2 + k;
  }
  return fx + fy - x;
}
void start(int l, int r) {
  if ((l + r) / 2 == l) {
    if (getnum((l + r) / 2) <= m) fans = (l + r) / 2;
    return;
  }
  int mid = (l + r) / 2;
  if (getnum(mid) <= m) {
    fans = max(fans, mid);
    start(mid, r);
  } else
    start(l, mid);
}
void init() { cin >> n >> m >> k; }
int main() {
  init();
  start(1, m);
  cout << fans << endl;
  return 0;
}
