#include <bits/stdc++.h>
using namespace std;
int MAX = 1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > cord;
  int mx = 0, mn = MAX;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    cord.push_back(make_pair(l, r));
    mn = min(l, mn);
    mx = max(r, mx);
  }
  bool mark = 1;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (cord[i].first == mn && cord[i].second == mx) {
      mark = 0;
      index = i + 1;
    }
  }
  if (mark)
    cout << "-1\n";
  else
    cout << index << "\n";
  return 0;
}
