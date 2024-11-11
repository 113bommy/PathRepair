#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    int ct = 0;
    cin >> a >> b;
    int diff = abs(a - b);
    int x = diff / 5;
    diff -= 5 * x;
    ct += x;
    x = diff / 2;
    diff -= 2 * x;
    ct += x;
    ct += diff;
    cout << ct << endl;
  }
}
