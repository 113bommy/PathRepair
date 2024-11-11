#include <bits/stdc++.h>
using namespace std;
int a, b, r;
int main() {
  cin >> a >> b >> r;
  r *= 2;
  if (r > a || r > b) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
  return 0;
}
