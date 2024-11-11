#include <bits/stdc++.h>
using namespace std;
void solve() {
  int k;
  cin >> k;
  int s = sqrt(k);
  if ((s * s) != k) s += 1;
  int c = s;
  int r = 1;
  int res = (s - 1) * (s - 1) + 1;
  while (r <= s) {
    if (res == k) {
      cout << r << " " << c << "\n";
      return;
    }
    res++;
    r++;
  }
  r = s;
  c = s - 1;
  while (c >= 0) {
    if (res == k) {
      cout << r << " " << c << "\n";
      return;
    }
    res++;
    c--;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
