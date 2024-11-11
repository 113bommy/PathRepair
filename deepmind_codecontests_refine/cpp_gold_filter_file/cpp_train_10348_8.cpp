#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c[10001], d[100001], i;
  cin >> a >> b;
  cout << a + b - 1 << endl;
  for (i = 1; i <= b; i++) {
    cout << 1 << " " << i << endl;
  }
  for (i = 2; i <= a; i++) {
    cout << i << " " << b << endl;
  }
}
