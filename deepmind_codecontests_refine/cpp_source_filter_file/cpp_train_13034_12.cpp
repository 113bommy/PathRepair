#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read() {
  register int s = 0, w = 1;
  register char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return s * w;
}
const int N = 1e6 + 10;
long long a[N], sum, xo, ch;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    xo = a[0];
    for (int i = 1; i < n; i++) xo ^= a[i];
    if (sum == xo * 2) {
      cout << 0 << endl << endl;
      continue;
    }
    ch = xo * 2 - sum;
    if (ch % 2 == 0 && ch > 0) {
      cout << 2 << endl;
      cout << ch / 2 << " " << ch / 2 << endl;
      continue;
    }
    cout << 2 << endl;
    cout << xo << " " << sum << endl;
  }
  return 0;
}
