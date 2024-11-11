#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, k;
  cin >> n >> w;
  vector<int> b;
  for (int i = 0; i < 2 * n; i++) {
    cin >> k;
    b.push_back(k);
  }
  sort(b.begin(), b.end());
  int mig = b[0], mib = b[n];
  double a, f, d;
  a = (double)(2 * min(mib * 0.5, (double)mig) * n +
               n * min(mib * 0.5, (double)mig));
  f = (double)(min(mig * 2, mib) * n / 2.0 + n * min(mig * 2, mib));
  d = (double)w;
  double res = min(a, min(f, d));
  cout << fixed << setprecision(6) << res;
  return 0;
}
