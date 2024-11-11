#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, x, y, i;
  cin >> n >> x >> y;
  if (y < n) {
    cout << "-1\n";
    return 0;
  }
  long long int a = y - (n - 1);
  long long int b = x - (n - 1);
  if (a * a >= b) {
    for (i = 0; i < n - 1; i++) cout << "1\n";
    cout << a << "\n";
  } else {
    cout << "-1\n";
  }
  return 0;
}
