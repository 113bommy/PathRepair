#include <bits/stdc++.h>
using namespace std;
long long k, b, n, t, r1, r2, l;
long long v[1000000], sum[1000000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k >> b >> n >> t;
  if (t == 1) {
    cout << 1 << endl;
    ;
    return 0;
  }
  long long x = 1;
  while (x <= t) {
    x = k * x + b;
    n--;
  }
  n++;
  cout << max(0LL, n) << endl;
  ;
  return 0;
}
