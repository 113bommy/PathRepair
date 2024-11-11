#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, a;
  cin >> n;
  cin >> a;
  if (a & 1) {
    cout << a / 2 + 1 << endl;
  } else {
    cout << n / 2 - a / 2 + 1 << endl;
  }
  return 0;
}
