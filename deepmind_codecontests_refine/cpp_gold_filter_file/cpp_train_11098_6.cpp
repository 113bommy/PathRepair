#include <bits/stdc++.h>
using namespace std;
int main() {
  char c1, c2;
  int n;
  cin >> c1 >> c2;
  cin >> n;
  if (n == 0) {
    cout << "undefined";
    return 0;
  }
  int as1 = int(c1);
  int as2 = int(c2);
  int in1, in2;
  if (as1 == 118)
    in1 = 0;
  else if (as1 == 60)
    in1 = 1;
  else if (as1 == 94)
    in1 = 2;
  else
    in1 = 3;
  if (as2 == 118)
    in2 = 0;
  else if (as2 == 60)
    in2 = 1;
  else if (as2 == 94)
    in2 = 2;
  else
    in2 = 3;
  int f1 = (in1 + n) % 4;
  int comp1 = in2;
  if (as1 == 118)
    in1 = 0;
  else if (as1 == 62)
    in1 = 1;
  else if (as1 == 94)
    in1 = 2;
  else
    in1 = 3;
  if (as2 == 118)
    in2 = 0;
  else if (as2 == 62)
    in2 = 1;
  else if (as2 == 94)
    in2 = 2;
  else
    in2 = 3;
  int f2 = (in1 + n) % 4;
  int comp2 = in2;
  if (f1 == comp1 && f2 == comp2)
    cout << "undefined";
  else if (f1 == comp1)
    cout << "cw";
  else
    cout << "ccw";
}
