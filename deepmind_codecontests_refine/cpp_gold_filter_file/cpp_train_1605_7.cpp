#include <bits/stdc++.h>
using namespace std;
int n, lC, rC, ql, qr, t, l[100003], r[100003], best = 2e9;
int main() {
  cin >> n >> lC >> rC >> ql >> qr;
  for (int i = 1; i <= n && cin >> t; i++)
    l[i] = l[i - 1] + t * lC, r[i - 1] = t * rC;
  for (int i = n - 1; i >= 0; i--) r[i] += r[i + 1];
  for (int i = 0; i <= n; i++)
    best = min(best, l[i] + r[i] + (i > n - i) * ql * (2 * i - n - 1) +
                         (i < n - i) * qr * (n - 2 * i - 1));
  cout << best;
  return 0;
}
