#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int MAXR = 1e5 + 5;
int ok[MAXR];
int main() {
  ios::sync_with_stdio(false);
  long long n, m, i, l, r, a;
  long long minl = INF, maxr = -1;
  long long sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    sum += a;
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> l >> r;
    ok[l]++;
    ok[r + 1]--;
  }
  for (i = 0; i < MAXR; i++) {
    ok[i] += ok[i - 1];
  }
  for (i = sum; i < MAXR; i++) {
    if (ok[i]) break;
  }
  if (i >= MAXR)
    cout << i << endl;
  else
    cout << -1 << endl;
  return 0;
}
