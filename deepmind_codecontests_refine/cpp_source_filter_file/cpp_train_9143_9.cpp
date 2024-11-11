#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (min(b, d) - max(a, c)) << endl;
}
