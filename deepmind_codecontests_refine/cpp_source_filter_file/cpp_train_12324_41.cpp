#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = 0, counter = 0;
  string xIncDec;
  do {
    cin >> xIncDec;
    if (xIncDec == "x++")
      x++;
    else if (xIncDec == "++x")
      ++x;
    else if (xIncDec == "x--")
      x--;
    else if (xIncDec == "--x")
      --x;
    counter++;
  } while (counter < n);
  cout << x << endl;
  return 0;
}
