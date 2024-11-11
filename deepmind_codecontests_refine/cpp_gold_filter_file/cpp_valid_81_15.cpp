#include <bits/stdc++.h>
using namespace std;
int pre1[300010], pre2[300010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, n, q, a, b, pre;
  string st;
  cin >> t;
  while (t--) {
    cin >> n >> q >> st;
    pre1[0] = pre2[0] = 0;
    for (int i = 0; i < n; i++)
      pre1[i + 1] =
          pre1[i] + ((st[i] == '+') ? 1 : -1) * ((i % 2 == 0) ? 1 : -1);
    for (int i = 0; i < n; i++)
      pre2[i + 1] =
          pre2[i] + ((st[i] == '+') ? 1 : -1) * ((i % 2 == 0) ? -1 : 1);
    while (q--) {
      cin >> a >> b;
      a--;
      b--;
      pre = ((a % 2 == 0) ? pre1[b + 1] - pre1[a] : pre2[b + 1] - pre2[a]);
      if (pre == 0)
        cout << "0\n";
      else {
        if ((b - a + 1) % 2)
          cout << "1\n";
        else
          cout << "2\n";
      }
    }
  }
}
