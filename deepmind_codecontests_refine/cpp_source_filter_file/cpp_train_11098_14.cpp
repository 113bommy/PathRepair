#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
map<char, int> M;
int main() {
  M['^'] = 0, M['>'] = 1, M['v'] = 2, M['<'] = 3;
  char beg, end;
  int n;
  cin >> beg >> end >> n;
  n = n % 4;
  if (abs(M[beg] - M[end]) == 2 && n % 4 == 2)
    cout << "undefined" << endl;
  else if ((M[beg] + n) % 4 == M[end])
    cout << "cw" << endl;
  else
    cout << "ccw" << endl;
}
