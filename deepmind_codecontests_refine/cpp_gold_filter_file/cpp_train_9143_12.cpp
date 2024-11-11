#include <bits/stdc++.h>
using namespace std;

int main() {

  int a, b, c, d, s;
  cin >> a >> b >> c >> d;
  s = max(0, min(b, d) - max(a, c));
  cout << s << endl;
}