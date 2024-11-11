#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + c > b + d)
    cout << "First";
  else
    cout << "Second";
  return 0;
}
