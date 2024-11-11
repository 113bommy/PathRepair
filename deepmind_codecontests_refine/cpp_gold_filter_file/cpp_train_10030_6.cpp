#include <bits/stdc++.h>
using namespace std;
int a, b, r;
int main() {
  cin >> a >> b >> r;
  if (a >= 2 * r && b >= 2 * r) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }
  return 0;
}
