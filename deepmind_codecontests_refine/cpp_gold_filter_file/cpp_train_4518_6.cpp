#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int main() {
  cin >> a >> b >> n;
  for (int i = -1000; i <= 1000; i++) {
    long long pok = pow(i, n);
    if (pok * a == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "No solution" << endl;
  return 0;
}
