#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, pos, l, r;
  cin >> n >> pos >> l >> r;
  if (l == 1 && r == n)
    cout << "0" << endl;
  else if (l == 1 && r != n)
    cout << abs(l - pos) + 1 << endl;
  else if (l != 1 && r == n)
    cout << abs(r - pos) + 1 << endl;
  else
    cout << r - l + min(abs(pos - l), abs(r - pos)) + 2 << endl;
}
