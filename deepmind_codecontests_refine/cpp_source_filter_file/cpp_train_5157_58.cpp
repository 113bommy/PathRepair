#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  char last = 'U';
  long long x, y;
  cin >> x >> y;
  long long lx = x, ly = y;
  char cur;
  long long count = 0;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    if (lx == x) {
      if (y > ly)
        cur = 'U';
      else
        cur = 'D';
    } else {
      if (x > lx)
        cur = 'R';
      else
        cur = 'L';
    }
    if (false) cerr << last << cur << " ";
    if (last == 'L' && cur == 'U')
      count++;
    else if (last = 'R' && cur == 'D')
      count++;
    else if (last == 'D' && cur == 'L')
      count++;
    else if (last == 'U' && cur == 'R')
      count++;
    last = cur;
    lx = x;
    ly = y;
    if (false) cerr << " " << count << '\n';
  }
  cout << count << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL),
      cout << setprecision(14);
  ;
  long long t = 1;
  while (t--) {
    solve();
  }
}
