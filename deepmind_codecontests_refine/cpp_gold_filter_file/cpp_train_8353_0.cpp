#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> co(26, 0);
    for (char c : s) ++co[c - 'a'];
    for (int l = n; l >= 1; --l) {
      int o = 0, i = 0;
      vector<bool> seen(l, false);
      while (!seen[i]) {
        ++o;
        seen[i] = true;
        i = (i + k) % l;
      }
      int u = 0;
      for (int c = 0; c < 26; ++c) u += co[c] / o;
      if (u * o >= l) {
        cout << l << "\n";
        break;
      }
    }
  }
  return 0;
}
