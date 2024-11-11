#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, pos;
  cin >> n;
  cin >> a;
  cin >> b;
  pos = n - a;
  if (pos < b) {
    cout << pos << endl;
  } else {
    cout << b + 1 << endl;
  }
  return 0;
}
