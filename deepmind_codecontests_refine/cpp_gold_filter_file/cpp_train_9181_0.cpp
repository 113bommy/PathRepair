#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > sat(18, vector<int>(18, 0));
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first * b.second == b.first * b.second) return a.first > b.first;
  return a.first * b.second > b.first * b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t, n, m, p, s, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<pair<int, int> > h;
    for (int i = 0; i < m; i++) {
      cin >> p >> s;
      h.push_back({p, s});
    }
    sort(h.begin(), h.end());
    vector<int> end(m, 0);
    end[m - 1] = h[m - 1].second;
    for (int i = m - 2; i >= 0; i--) end[i] = max(end[i + 1], h[i].second);
    int flag = 1, curr = 0, currs = 0, moves = 0;
    for (int i = 0; i < n; i++) {
      currs = max(a[i], currs);
      x = upper_bound(h.begin(), h.end(), make_pair(currs, 0)) - h.begin();
      if (x == m) {
        flag = 0;
        break;
      }
      curr++;
      if (end[x] < curr) {
        moves++;
        curr = 1;
        currs = a[i];
      }
    }
    if (flag)
      cout << moves + 1 << "\n";
    else
      cout << -1 << "\n";
  }
}
