#include <bits/stdc++.h>
using namespace std;
int n, m, q, j, k, ans, i;
vector<int> my;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> q;
  for (i = 1; i <= q; i++) {
    int x;
    cin >> x;
    my.push_back(x);
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      int x;
      cin >> x;
      vector<int> v;
      v.push_back(x);
      for (k = 0; k < my.size(); k++) {
        if (my[k] != x)
          v.push_back(my[k]);
        else {
          ans += k + 1;
        }
      }
      my = v;
    }
  }
  cout << ans << endl;
}
