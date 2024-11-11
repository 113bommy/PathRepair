#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int a, b, c;
  cin >> a >> b >> c;
  if (a == b)
    cout << 2 * c + 2 * a;
  else {
    cout << 2 * c + 2 * abs(b - a) + 1;
  }
  return 0;
}
