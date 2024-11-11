#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c, d;
  cin >> a >> b >> c >> d;
  int n = ceil((b) / c);
  int s = ceil((a * n) / d);
  cout << s;
}
