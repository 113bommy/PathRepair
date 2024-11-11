#include <bits/stdc++.h>
using namespace std;
int pb, pc, ps;
int nb, nc, ns;
int lb, lc, ls;
long long int fb, fc, fs;
long long int price(long long int x) {
  fb = max(x * lb - nb, (long long int)0);
  fc = max(x * lc - nc, (long long int)0);
  fs = max(x * ls - ns, (long long int)0);
  long long int p = fb * pb + fc * pc + fs * ps;
  return p;
}
int main() {
  int i, j, k;
  int n, m;
  long long int r;
  string s;
  cin >> s;
  n = s.length();
  lb = lc = ls = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 'B')
      lb++;
    else if (s[i] == 'C')
      lc++;
    else
      ls++;
  }
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;
  long long int high, low, mid, z, ans = 0;
  low = 0, high = r + 1000, mid = 0;
  while (low <= high) {
    mid = (low + high) / 2;
    z = price(mid);
    if (z == r) {
      cout << mid << endl;
      return 0;
    }
    if (z > r)
      high = mid - 1;
    else
      low = mid + 1, ans = mid;
  }
  cout << ans << endl;
  return 0;
}
