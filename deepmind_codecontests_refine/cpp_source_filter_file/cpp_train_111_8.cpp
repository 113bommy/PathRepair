#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, sum = 0, max = -1;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a;
    sum += a;
    max = (a > max ? a : max);
  }
  while (max * n - 2 * sum < 0) max++;
  cout << max;
  return 0;
}
