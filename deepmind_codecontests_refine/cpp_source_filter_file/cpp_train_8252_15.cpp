#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    cout << n << endl;
    for (long long int i = 0; i < n; i++) cout << i << " ";
    cout << endl;
  }
}
