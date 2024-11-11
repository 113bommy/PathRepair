#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int lft[N + 10], rght[N + 10], f[N + 10], ind[N + 10], l, r, n, a, mn, mx;
bool cmp(int i, int j) { return f[i] > f[j]; }
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i <= N; i++) {
    lft[i] = -1;
    rght[i] = -1;
    f[i] = 0;
    ind[i] = i;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (lft[a] == -1) lft[a] = i;
    rght[a] = i;
    f[a]++;
  }
  sort(ind + 1, ind + N + 1, cmp);
  mn = n + 10;
  mx = f[ind[1]];
  for (int i = 1, j; i <= N; i++) {
    j = ind[i];
    if (f[j] < mx) break;
    if (rght[j] - lft[j] < mn) {
      mn = rght[j] - lft[j];
      r = rght[j];
      l = lft[j];
    }
  }
  cout << l << " " << r << "\n";
  return 0;
}
