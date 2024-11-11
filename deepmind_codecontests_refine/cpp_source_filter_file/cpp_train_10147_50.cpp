#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, n, m;
  cin >> n;
  if (n % 2 == 0) {
    cout << "white" << endl;
    if (n == 2)
      cout << "1 2" << endl;
    else
      cout << "2 2" << endl;
  } else if (n % 2 == 1) {
    cout << "black" << endl;
  }
}
