#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    int temp = a;
    a = b;
    b = temp;
  }
  cout << " " << (b - a) / 2 << "\n";
  return 0;
}
