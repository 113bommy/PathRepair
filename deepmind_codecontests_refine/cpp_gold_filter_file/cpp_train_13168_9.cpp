#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long s[maxn + 1], b[maxn + 1];
int main() {
  char a;
  int n, fi, se, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a >> fi >> se;
    if (a == 'B')
      b[fi] += se;
    else
      s[fi] += se;
  }
  int p = 0, idx = 0;
  for (int i = 0; i <= maxn; i++) {
    if (p == k) break;
    if (s[i] > 0) {
      p++;
      idx = i;
    }
  }
  for (int i = idx; i >= 0; i--)
    if (s[i] > 0) cout << 'S' << " " << i << " " << s[i] << endl;
  for (int i = maxn, x = 0; i >= 0; i--) {
    if (x == k) break;
    if (b[i] > 0) {
      cout << 'B' << " " << i << " " << b[i] << endl;
      x++;
    }
  }
  return 0;
}
