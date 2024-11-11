#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 3;
int x[MAXN], b[MAXN], go[MAXN];
double DP[MAXN];
bool ok(double r, int n, int l) {
  for (int i = 1; i <= n; i++) {
    DP[i] = -1e17;
    for (int j = 0; j < i; j++) {
      double gap = b[i] * r - sqrt(abs(x[i] - x[j] - l)) + DP[j];
      if (DP[i] < gap) {
        DP[i] = gap;
        go[i] = j;
      }
    }
  }
  return DP[n] > 1e-9;
}
int main() {
  int n, l;
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> b[i];
  }
  double lo = 0.0, hi = 1e4, res = -1;
  for (int i = 0; i < 64; i++) {
    double mid = (lo + hi) / 2.0;
    if (ok(mid, n, l))
      res = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  vector<int> trace;
  int curr = n;
  while (curr > 0) {
    trace.push_back(curr);
    curr = go[curr];
  }
  reverse(trace.begin(), trace.end());
  for (int i = 0; i < (int)(trace.size()); i++) {
    if (i > 0) cout << ' ';
    cout << trace[i];
  }
  return 0;
}
