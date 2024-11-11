#include <bits/stdc++.h>
#pragma GCC optimize "-O3"
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  setIO();
  int p1, p2, p3, p4;
  int a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int lim = min(min(p1, p2), min(p3, p4));
  if (lim < a) {
    cout << 0 << '\n';
    return 0;
  }
  cout << (min(lim, b) - a) << '\n';
}
