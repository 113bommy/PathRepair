#include <bits/stdc++.h>
using namespace std;
long long okr(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return (a / b) + 1;
}
int main() {
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  if ((n - k < l) || (m > n) || (l > n) || okr(k + l, m) * m > n || k + l > n)
    cout << "-1";
  else
    cout << okr(k + l, m);
  return 0;
}
