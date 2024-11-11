#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  long long int x = ceil(a * c * 1.0 / 100);
  x -= b;
  if (x < 0) x = 0;
  cout << x << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int t;
  solve();
  return 0;
}
