#include <bits/stdc++.h>
using namespace std;
long long int n;
long long int f(long long int x) {
  long long int sq = sqrt(x);
  for (long long int i = 2; i <= sq; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  cin >> n;
  if (f(n)) {
    cout << 1 << endl << n << endl;
    return 0;
  }
  cout << 3 << endl;
  cout << 1 << ' ';
  n--;
  for (long long int i = 1; i < n; i++) {
    if (f(i) && f(n - i)) return cout << i << ' ' << n - i << endl, 0;
  }
}
