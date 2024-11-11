#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  long long int nb, ns, nc, pb, ps, pc, r, cntb = 0, cnts = 0, cntc = 0;
  cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
  for (char c : s) {
    if (c == 'B') cntb++;
    if (c == 'S') cnts++;
    if (c == 'C') cntc++;
  }
  long long int ans = 0, low = 0, high = 1e18;
  while (low <= high) {
    long long int mid = low + (high - low) / 2;
    long long int req = max(0ll, mid * cntb - nb) * pb +
                        max(0ll, mid * cnts - ns) * ps +
                        max(0ll, mid * cntc - nc) * pc;
    if (req <= r) {
      ans = max(ans, mid);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
