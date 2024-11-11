#include <bits/stdc++.h>
using namespace std;
double dis(int x1, int y1, int x2, int y2) {
  return sqrt((powl((x1 - x2), 2)) + (powl((y1 - y2), 2)));
}
int main() {
  long long n, h, k, s = 0, r = 0;
  cin >> n >> h >> k;
  int a[n + 1];
  for (int i = int(0); i <= int(n - 1); i++) cin >> a[i];
  for (int i = int(0); i <= int(n - 1); i++) {
    if (s + a[i] > h) {
      r += s / k;
      s = s % k;
      if (s + a[i] > h) {
        r++;
        s = 0;
      }
    }
    s += a[i];
  }
  if (s != 0) r += s / k;
  if (s % k != 0) r++;
  cout << r;
}
