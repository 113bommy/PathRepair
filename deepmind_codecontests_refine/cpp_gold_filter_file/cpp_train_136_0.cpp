#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int res;
  if ((a * c) % b == 0)
    res = (a * c) / b;
  else
    res = (a * c) / b + 1;
  cout << res - c;
}
