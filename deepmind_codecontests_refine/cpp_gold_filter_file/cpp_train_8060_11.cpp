#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long x[n + 1000];
  for (long long i = 0; i < n; ++i) cin >> x[i];
  sort(x, x + n);
  cout << x[n - m];
}
