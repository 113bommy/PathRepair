#include <bits/stdc++.h>
using namespace std;
int n, i, t[1000005], cc, pos;
bool NonDec(int pp) {
  for (i = 1; i < pp; i++)
    if (t[i] < t[i - 1]) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (i = 0; i < n; i++) cin >> t[i];
  if (n == 1)
    cout << "0" << endl;
  else if (n == 2) {
    if (t[0] <= t[1])
      cout << "0" << endl;
    else
      cout << "1" << endl;
  } else {
    cc = 0;
    pos = n - 1;
    while (pos > 0) {
      if (t[pos] >= t[pos - 1]) {
        cc++;
        pos--;
      } else
        break;
    }
    if (pos == 0)
      cout << "0" << endl;
    else if (NonDec(pos) && t[0] >= t[n - 1])
      cout << cc + 1 << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
