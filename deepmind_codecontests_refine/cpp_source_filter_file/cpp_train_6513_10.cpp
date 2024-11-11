#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  int last = -1;
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      int l = i - last - 1;
      v.push_back(make_pair(l, last + 1));
      last = i;
    }
  }
  v.push_back(make_pair(n - last - 1, last + 1));
  int col = 0;
  for (int i = 0; i < v.size(); i++) {
    col += v[i].first / b;
  }
  int ans = max(0, col - a) + 1;
  cout << ans << endl;
  for (int i = 0; i < v.size(); i++) {
    if (ans <= 0) break;
    int x = b - 1;
    while (x < v[i].first) {
      if (ans > 0) {
        cout << x + v[i].second << " ";
        ans--;
        x += b;
      } else {
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
