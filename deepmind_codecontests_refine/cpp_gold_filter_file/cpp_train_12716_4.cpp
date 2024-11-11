#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if (min(a, b) != max(a, b))
    cout << (2 * min(a, b) + 1 + 2 * c);
  else
    cout << (a + b + 2 * c);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
