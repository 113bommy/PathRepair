#include <bits/stdc++.h>
using namespace std;
int ones(long long x) {
  int res = 0;
  while (x) {
    if (x & 1) res++;
    x /= 2;
  }
  return res;
}
long long n, p;
int main() {
  cin >> n >> p;
  if (p == 0) {
    cout << ones(n) << endl;
    return 0;
  }
  for (int i = 1; i <= 10000; i++) {
    long long m = n - p * i;
    if (m <= i) break;
    if (i >= ones(m)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
