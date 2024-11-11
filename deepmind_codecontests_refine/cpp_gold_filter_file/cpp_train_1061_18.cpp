#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int c, in, fe = 0, r;
  cin >> c;
  in = c / 3;
  r = c % 3;
  if (r >= 2) in++;
  if (in >= 12) {
    fe = in / 12;
    in = in - 12 * fe;
  }
  cout << fe << " " << in << endl;
}
