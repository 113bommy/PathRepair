#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int an, s = 0, a;
  while (n--) {
    cin >> a;
    if (a > 0)
      s += a;
    else {
      if (s == 0)
        an++;
      else
        s--;
    }
  }
  cout << an << endl;
}
