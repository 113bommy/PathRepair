#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x;
    vector<pair<int, pair<int, int> > > q;
    for (int j = 1; j <= x; j++) {
      cin >> y;
      q.push_back(make_pair(y, make_pair(j, m - x + j)));
    }
    if (x != m) {
      q.push_back(make_pair(0, make_pair(1, m - x)));
      q.push_back(make_pair(0, make_pair(m - x + 1, m)));
    }
    set<pair<pair<int, int>, int> > s;
    s.insert(make_pair(make_pair(1, m), -2e9));
    sort(q.begin(), q.end());
    for (auto it : q) {
      int l = it.second.first, r = it.second.second;
      auto itt = s.lower_bound(make_pair(make_pair(l, -1), -1));
      auto ittt = itt;
      vector<pair<pair<int, int>, int> > del, add;
      while (itt != s.end() && itt->first.first <= r) {
        del.push_back(*itt);
        if (itt->first.second > r) {
          add.push_back(
              make_pair(make_pair(r + 1, itt->first.second), itt->second));
        }
        itt++;
      }
      itt = ittt;
      if (itt != s.begin()) {
        itt--;
        while (l <= itt->first.second) {
          del.push_back(*itt);
          if (itt->first.first < l) {
            add.push_back(
                make_pair(make_pair(itt->first.first, l - 1), itt->second));
          }
          if (itt == s.begin()) {
            break;
          }
          itt--;
        }
      }
      for (auto stt : del) {
        s.erase(stt);
      }
      add.push_back(make_pair(make_pair(l, r), it.first));
      for (auto stt : add) {
        s.insert(stt);
      }
    }
    for (auto it : s) {
      int l = it.first.first, r = it.first.second, val = it.second;
      a[l] += val;
      a[r + 1] -= val;
    }
  }
  for (int i = 1; i <= m; i++) {
    a[i] += a[i - 1];
    cout << a[i] << " ";
  }
}
