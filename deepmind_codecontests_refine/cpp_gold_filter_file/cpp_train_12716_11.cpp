#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  cout << a + min(a + 1, b) + 2 * c << endl;
  return 0;
}
