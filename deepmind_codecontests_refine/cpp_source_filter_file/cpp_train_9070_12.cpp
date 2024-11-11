#include <bits/stdc++.h>
using namespace std;
int main() {
  int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  int ans = h1 * 2 + h2 * 2 + w1 + w2;
  if (w1 > w2)
    cout << ans + (w1 - w2 - 1) + 5 << endl;
  else
    cout << ans + 3 << endl;
}
