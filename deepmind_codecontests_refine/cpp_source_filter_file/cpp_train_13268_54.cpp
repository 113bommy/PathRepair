#include <bits/stdc++.h>
using namespace std;
int x, y, n, cou;
int main() {
  pair<int, int> foo;
  cin >> n;
  while (n != 0) {
    cin >> x >> y;
    foo = make_pair(x, y);
    if (foo.first < foo.second - 2) cou++;
    n--;
  }
  cout << cou;
  return 0;
}
