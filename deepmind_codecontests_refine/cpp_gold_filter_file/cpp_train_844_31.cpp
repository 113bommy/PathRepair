#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  while (n >= 4) {
    cout << "abcd";
    n -= 4;
  }
  if (n == 3)
    cout << "abc";
  else if (n == 2)
    cout << "ab";
  else if (n == 1)
    cout << "a";
  cout << endl;
  return 0;
}
