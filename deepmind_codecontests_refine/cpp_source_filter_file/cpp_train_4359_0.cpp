#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << 3 - ((a == b) + (a == c) + (b == c)) << endl;
}
