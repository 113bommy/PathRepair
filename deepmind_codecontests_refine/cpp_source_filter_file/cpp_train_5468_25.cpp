#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int t, s;
  vector<pair<int, int> > change;
  for (int i = 0; i < m; i++) {
    cin >> t >> s;
    --t;
    s--;
    if (change.empty())
      change.push_back(make_pair(t, s));
    else {
      while (!change.empty() && change.back().second <= s) change.pop_back();
      if (change.empty() || change.back().first != t)
        change.push_back(make_pair(t, s));
    }
  }
  change.push_back(make_pair(0, -1));
  sort(a.begin(), a.begin() + change.front().second);
  int i = 0, j = change.front().second, jb = j;
  vector<int> b(a);
  for (int k = 0; k < change.size() - 1; k++) {
    while (j - i > change[k + 1].second) {
      if (!change[k].first) {
        b[jb--] = a[j--];
      } else {
        b[jb--] = a[i++];
      }
    }
  }
  for (i = 0; i < n; i++) cout << b[i] << " ";
  return 0;
}
