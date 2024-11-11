#include <bits/stdc++.h>
using namespace std;
int n, f = 0, d = 0;
int main(int argc, char **argv) {
  cin >> n;
  while (n > 2) {
    if (d > 11) {
      f++;
      d -= 12;
    }
    if (n >= 36) {
      n -= 36;
      f++;
      continue;
    }
    n -= 3;
    d++;
  }
  if (n == 2) d++;
  if (d == 12) {
    f++;
    d -= 12;
  }
  cout << f << " " << d << endl;
  return 0;
}
