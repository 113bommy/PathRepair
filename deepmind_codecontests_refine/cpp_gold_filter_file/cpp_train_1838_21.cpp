#include <bits/stdc++.h>
using namespace std;
long long p;
int k, d;
long long a[100000];
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> p >> k;
  long long neg = -1;
  a[0] = p;
  p /= k;
  while (p || a[d] < 0) {
    a[d] += neg * p * k;
    if (a[d] < 0) {
      a[d] += k;
      p++;
    }
    a[++d] += neg * p;
    neg = -neg;
    p /= k;
  }
  cout << ++d << '\n';
  cout << a[0];
  for (int i = 1; i < d; i++) cout << ' ' << a[i];
  cout << '\n';
  return 0;
}
