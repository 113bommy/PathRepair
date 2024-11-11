#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, a;
  vector<long long> v;
  cin >> n >> x >> y;
  a = y - (n - 1);
  if (a * a + (n - 1) < x || n > y)
    cout << -1 << endl;
  else {
    cout << a << endl;
    for (int i = 0; i < n - 1; i++) cout << 1 << endl;
  }
  return 0;
}
