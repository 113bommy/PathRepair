#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long a[3];
  a[0] = 0, a[1] = 0, a[2] = 0;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      a[0]++;
    else if (s[i] == 'S')
      a[1]++;
    else
      a[2]++;
  }
  long long b[3], c[3];
  for (int i = 0; i < 3; i++) cin >> b[i];
  for (int i = 0; i < 3; i++) cin >> c[i];
  long long r;
  cin >> r;
  long long lo = 0, hi = 1e13, mid = (lo + hi) / 2, cnt = 0, f = 0;
  while (lo < hi && cnt <= 200) {
    cnt++;
    mid = (lo + hi + 1) / 2;
    long long need = 0;
    for (int i = 0; i < 3; i++) {
      long long x = max(0LL, (mid * a[i]) - b[i]);
      need += (x * c[i]);
    }
    if (need <= r) {
      lo = mid;
      f = max(f, lo);
    } else
      hi = mid - 1;
  }
  cout << f << endl;
  return 0;
}
