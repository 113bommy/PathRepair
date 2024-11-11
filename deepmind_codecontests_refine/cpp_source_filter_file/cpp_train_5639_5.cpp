#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, s = 0, S, i, a, b;
  cin >> x;
  while (x--) {
    cin >> a >> b;
    s = s - a + b;
    S = max(s, S);
  }
  cout << S;
}
