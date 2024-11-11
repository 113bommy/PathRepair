#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  int n, valore, s[100002], m, worm;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> valore;
    if (i == 0)
      s[1] = valore;
    else
      s[i + 1] = s[i] + valore;
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> valore;
    cout << lower_bound(s, s + n, valore) - s << endl;
  }
  return 0;
}
