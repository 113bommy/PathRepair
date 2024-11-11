#include <bits/stdc++.h>
using namespace std;
long long n, k, a[200100], d[200100];
void read(void) {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
}
void kill(void) {
  long long t = 2, p = 1, m = n;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[p] + (t - 2) * a[p];
    if (d[i] - (t - 1) * (m - t) * a[i] < k) {
      m--;
      cout << i << "\n";
      continue;
    }
    t++;
    p = i;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  read();
  kill();
  return 0;
}
