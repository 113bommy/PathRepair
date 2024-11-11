#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  long long r = 0, l = 0;
  map<long long, long long> p;
  long long x;
  char y;
  while (q--) {
    cin >> y >> x;
    if (y == 'L') {
      l--;
      p[x] = l;
    } else if (y == 'R') {
      r++;
      p[x] = r;
    } else {
      if (p[x] < 0) {
        cout << min(abs(l - p[x]), r - p[x] - 1) << "\n";
      } else {
        cout << min(r - p[x], abs(l - p[x]) - 1) << "\n";
      }
    }
  }
}
