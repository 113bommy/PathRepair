#include <bits/stdc++.h>
using namespace std;
long long calc(int n, int d, long long m, int l) {
  for (long long i = 0; i < n; i++) {
    long long high = i * m + l;
    long long x = high % d;
    if (d < (x + m - l)) {
      return high + (d - x);
    }
  }
  long long high = (n - 1) * m + l;
  long long x = high % d;
  return high + (d - x);
}
int main() {
  int n, d, m, l;
  scanf("%d %d %d %d", &n, &d, &m, &l);
  cout << calc(n, d, m, l) << '\n';
}
