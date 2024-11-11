#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  if (a < b or (a & 1) != (b & 1))
    cout << -1 << '\n';
  else
    cout << (a - b) / 2 << ' ' << (a + b) / 2 << '\n';
  return 0;
}
