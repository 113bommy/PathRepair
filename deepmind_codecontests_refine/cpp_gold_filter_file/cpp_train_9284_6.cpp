#include <bits/stdc++.h>
using namespace std;
const int N = 300 * 1000 + 10, K = 10;
int mod = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  int a, b;
  while (q--) {
    string s;
    cin >> a >> b;
    cin >> s;
    int n = s.size();
    vector<int> v;
    int cnt = 0;
    s += 'X';
    for (int i = 0; i < n + 1; i++) {
      if (s[i] == '.')
        cnt++;
      else {
        if (cnt >= b) v.push_back(cnt);
        cnt = 0;
      }
    }
    sort(v.begin(), v.end());
    if (!v.size()) {
      cout << "No\n";
      continue;
    }
    cnt = 0;
    for (auto u : v)
      if (u >= 2 * b) cnt++;
    if (cnt > 1 || v[0] < a) {
      cout << "No\n";
    } else if (!cnt) {
      cout << (v.size() % 2 == 1 ? "Yes" : "No") << '\n';
    } else {
      bool f = 0;
      int x = v.back();
      for (int i = 0; i + a <= x; i++) {
        int l = i, r = x - i - a;
        if (r > l) continue;
        if (b <= l && l < a) continue;
        if (b <= r && r < a) continue;
        if (l >= 2 * b) continue;
        int w = v.size() - 1 + (l >= a) + (r >= a);
        if (w % 2 == 0) {
          cout << "Yes\n";
          f = 1;
          break;
        }
      }
      if (!f) cout << "No\n";
    }
  }
}
