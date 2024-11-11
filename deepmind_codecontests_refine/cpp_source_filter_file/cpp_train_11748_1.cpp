#include <bits/stdc++.h>
using namespace std;
int main() {
  int X, a, b;
  cin >> X >> a >> b;
  cout << (a >= b ? "delicious" : (a + X <= b ? "safe" : "dangerous")) << endl;
}
