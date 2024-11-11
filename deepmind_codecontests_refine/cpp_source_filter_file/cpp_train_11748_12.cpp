#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, a, b;
  cin >> x >> a >> b;
  cout << (a > b ? "delicious" : (x >= b - a ? "safe" : "dangerous")) << endl;
}
