#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int diff = min(a, b);
  a -= diff;
  b -= diff;
  int same;
  if (0 == a) {
    same = 1 == b ? 0 : 0 == b % 2 ? b / 2 : b / 2;
  } else {
    same = 1 == a ? 0 : 0 == a % 2 ? a / 2 : a / 2;
  }
  cout << diff << " " << same;
  return 0;
}
