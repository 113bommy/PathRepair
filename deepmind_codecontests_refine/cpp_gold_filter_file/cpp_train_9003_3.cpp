#include <bits/stdc++.h>
using namespace std;
int conver(long long x) {
  int a = 0;
  for (int i = 31; i >= 0; i--) {
    if (x & (1ll << i)) {
      ++a;
    }
  }
  return a;
}
int main() {
  long long x;
  cin >> x;
  int a = conver(x);
  cout << a << "\n";
}
