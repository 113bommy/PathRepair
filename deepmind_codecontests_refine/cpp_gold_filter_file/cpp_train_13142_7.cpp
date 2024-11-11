#include <bits/stdc++.h>
using namespace std;
long long int min1(long long int a) {
  long long int mx = 0, mi = 10;
  while (a) {
    mx = max(mx, a % 10);
    mi = min(mi, a % 10);
    a /= 10;
  }
  return mi * mx;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, k;
    cin >> a >> k;
    long long int tem = min1(a);
    while (--k && tem != 0) {
      a = a + tem;
      tem = min1(a);
    }
    cout << a << endl;
  }
  return 0;
}
