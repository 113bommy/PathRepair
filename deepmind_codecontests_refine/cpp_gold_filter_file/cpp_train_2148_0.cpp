#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, i;
  cin >> n;
  vector<long long> a(300000, n);
  for (i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a[x] = i;
  }
  long long x = -1;
  for (i = 0; i < 300000; i++) {
    if (x == -1 || a[i] < a[x]) {
      x = i;
    }
  }
  cout << x << '\n';
}
