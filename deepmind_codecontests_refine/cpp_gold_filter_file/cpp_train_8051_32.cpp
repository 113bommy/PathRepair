#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int x, s = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    s += x;
  }
  cout << (float)s / n << endl;
  return 0;
}
