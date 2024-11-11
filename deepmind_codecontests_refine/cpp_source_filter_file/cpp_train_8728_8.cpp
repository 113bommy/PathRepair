#include<bits/stdc++.h>
using namespace std;
int main() {
  int64_t x, y;
  cin >> x >> y;
  if (abs(x, y) <= 1) {
    cout << "Brown";
  } else {
    cout << "Alice";
  }
  return 0;
}