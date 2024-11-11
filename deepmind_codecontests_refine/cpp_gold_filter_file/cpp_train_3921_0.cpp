#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[100000], x, s = 0, z, y = 0, c = 0;
  cin >> x >> z;
  for (int i = 0; i < x; i++) {
    cin >> a[i];
    s += a[i];
  }
  y = a[0];
  for (int i = 0; i < x; i++) {
    y = +a[i];
    c = max((y % z) + ((s - y) % z), c);
  }
  cout << c << endl;
}
