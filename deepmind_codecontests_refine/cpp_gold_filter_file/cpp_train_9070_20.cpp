#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << w1 + w2 + 2 * (h1 + h2) + 4 + (w1 - w2) << endl;
  return 0;
}
