#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100099;
const int MAXM = 113;
const double eps = 1e-9;
int n;
int a[MAXN];
long long steps;
int main() {
  cin.sync_with_stdio();
  cout.sync_with_stdio();
  cin >> n;
  for (int i = 0, _n = (n); i < _n; i++) {
    cin >> a[i];
  }
  for (int i = 0, _n = (n - 1); i < _n; i++) {
    int t = 1;
    while (i + t * 2 < n) t <<= 1;
    steps += a[i];
    a[i + t] += a[i];
    a[i] = 0;
    cout << steps << "\n";
  }
  return 0;
}
