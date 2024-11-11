#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned int count;
  unsigned int a, b;
  unsigned int x;
  cin >> count;
  for (int i = 0; i < count; ++i) {
    cin >> a >> b;
    x = a & b;
    cout << (a ^ x) + (b ^ x);
  }
  return 0;
}
