#include <bits/stdc++.h>
using namespace std;
int main() {
  {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    bool ron;
    if (!d)
      ron = false;
    else if (!c)
      ron = true;
    else if (!b)
      ron = false;
    else if (!a)
      ron = true;
    else if (!f)
      ron = false;
    else if (!e)
      ron = true;
    else
      ron = a * c * e < b * d * f;
    printf("%s\n", ron ? "Ron" : "Hermione");
  }
  return 0;
}
