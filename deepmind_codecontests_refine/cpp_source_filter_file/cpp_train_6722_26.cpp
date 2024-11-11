#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int sq = sqrt(x) + 1;
  int a, b;
  for (int i = 1; i <= sq; i++) {
    if (x % i == 0) {
      a = i;
      b = x / i;
    }
  }
  cout << a << " " << b << endl;
}
