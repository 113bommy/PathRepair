#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, r;
  cin >> a >> b >> r;
  r = r * 2;
  if (((a / r) * (b / r)) == 0)
    cout << "Second";
  else
    cout << "First";
  return 0;
}
