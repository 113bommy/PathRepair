#include <bits/stdc++.h>
using namespace std;
long long n, res;
long long cal(long long n) {
  if (n == 0) return 0;
  return n / 2 + 2 * cal(n / 2);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cout << cal(n);
}
