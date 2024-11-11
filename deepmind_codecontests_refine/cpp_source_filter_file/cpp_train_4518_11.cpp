#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  for (int i = -1000; i <= 1000; i++) {
    if (a * pow(i, n) == b) {
      cout << i << endl;
      return 0;
    }
  }
  cout << "No solution" << endl;
  return 0;
}
