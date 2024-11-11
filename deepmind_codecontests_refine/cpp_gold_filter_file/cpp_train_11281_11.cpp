#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int> > out;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    vector<pair<pair<int, int>, int> > a;
    long long tt = 0;
    for (int j = 0; j < 2 * k - 1; j++) {
      int x, y;
      cin >> x >> y;
      a.push_back(make_pair((make_pair((x), (y))), (j + 1)));
      tt += y;
    }
    ++tt;
    tt /= 2;
    sort(a.begin(), a.end());
    for (int j = 0; j < 2 * k - 1; j += 2) tt -= a[j].first.second;
    vector<int> now;
    if (tt <= 0)
      for (int j = 0; j < 2 * k - 2; j += 2) now.push_back(a[j].second);
    else
      for (int j = 1; j < 2 * k - 2; j += 2) now.push_back(a[j].second);
    now.push_back(a.back().second);
    out.push_back(now);
  }
  for (auto x : out) {
    cout << "YES" << endl;
    for (int i = 0; i < x.size(); i++)
      cout << x[i] << (i + 1 == x.size() ? '\n' : ' ');
  }
  return 0;
}
