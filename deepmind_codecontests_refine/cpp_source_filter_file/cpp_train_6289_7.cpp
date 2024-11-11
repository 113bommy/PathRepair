#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a, b[100100], p[100100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> a;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) cin >> p[i];
  sort(b + 1, b + n + 1);
  sort(p + 1, p + m + 1);
  int le = -1, ri = min(n, m) + 1;
  while (le + 1 < ri) {
    int mi = (le + ri) / 2;
    long long cnt = 0;
    for (int i = 1; i <= mi; i++) {
      cnt += max(0LL, p[mi - i] - b[n - i]);
    }
    if (cnt > a) {
      ri = mi;
    } else {
      le = mi;
    }
  }
  long long tot = 0;
  for (int i = 1; i <= le; i++) tot += p[i];
  cout << le << ' ' << max(tot - a, 0LL) << endl;
  return 0;
}
