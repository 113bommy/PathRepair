#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  vector<pair<int, int> > xc(n);
  vector<pair<int, int> > yc(n);
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    cin >> y[i];
    xc[i].first = x[i];
    yc[i].first = y[i];
    xc[i].second = i;
    yc[i].second = i;
    p[i] = make_pair(x[i], y[i]);
  }
  sort(xc.begin(), xc.end());
  sort(yc.begin(), yc.end());
  sort(p.begin(), p.end(), [](pair<int, int> &f, pair<int, int> &s) -> bool {
    if (f.first < s.first)
      return true;
    else if (f.first > s.first)
      return false;
    else if (f.second < s.second)
      return true;
    else if (f.second >= s.second)
      return false;
    return false;
  });
  long long last = 1;
  long long pairs = 0;
  for (int i = 1; i < n; i++) {
    if (xc[i].first == xc[i - 1].first) {
      last++;
    } else {
      pairs += last * (last - 1) / 2;
      last = 1;
    }
  }
  pairs += last * (last - 1) / 2;
  last = 1;
  for (int i = 1; i < n; i++) {
    if (yc[i].first == yc[i - 1].first) {
      last++;
    } else {
      pairs += last * (last - 1) / 2;
      last = 1;
    }
  }
  pairs += last * (last - 1) / 2;
  last = 1;
  for (int i = 1; i < n; i++) {
    if (p[i].first == p[i - 1].first && p[i].second == p[i - 1].second) {
      last++;
    } else {
      pairs -= last * (last - 1) / 2;
      last = 1;
    }
  }
  pairs -= last * (last - 1) / 2;
  cout << pairs << endl;
  return 0;
}
