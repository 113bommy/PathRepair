#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, a, b;
  cin >> a >> b >> c;
  cout << min(c - a + b, 0) << endl;
}
