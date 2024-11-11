#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (int i = 0; i < n; i++) cin >> mp[i];
  vector<int> bc;
  for (int i = 0; i < m - 1; i++) {
    for (int j = 1; j < n; j++) {
      if (mp[j][i] == 'X' && mp[j - 1][i + 1] == 'X') {
        bc.push_back(i);
        break;
      }
    }
  }
  bc.push_back(n + 1);
  int q;
  cin >> q;
  while (q--) {
    int li, ri;
    cin >> li >> ri;
    li--;
    ri--;
    int l = 0, r = bc.size() - 1;
    while (l != r) {
      int m = (l + r) / 2;
      if (li <= bc[m])
        r = m;
      else
        l = m + 1;
    }
    if (bc[l] + 1 <= ri)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
