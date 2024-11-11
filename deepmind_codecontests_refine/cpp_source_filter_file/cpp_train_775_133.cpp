#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((a + b) & 1 ? "First" : "Second");
  return 0;
}
