#include <bits/stdc++.h>
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 1e-6;
const double PI = 3.141592653589793;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> t(n);
  vector<pair<int, int> > x(n), ans;
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> t[i] >> x[i].first;
    x[i].second = i;
  }
  int ti = 0, xi = 0, ass = 0;
  while (ass < t.size()) {
    vector<pair<int, int> > v(x.begin() + ass,
                              x.begin() + min(m, (int)x.size() - ass) + ass);
    ti = max(ti, t[min(m + ass, (int)t.size()) - 1]);
    ass += min(m, (int)t.size());
    sort((v).begin(), (v).end());
    for (int(i) = 0; (i) < (v.size()); (i)++) {
      ti += v[i].first - xi;
      int j = i;
      while (j < v.size() && v[j].first == v[i].first) {
        ans.push_back(make_pair(v[j].second, ti));
        j++;
      }
      xi = v[i].first;
      ti += (j - i) / 2 + 1;
      i = j - 1;
    }
    ti += xi;
    xi = 0;
  }
  sort((ans).begin(), (ans).end());
  for (int(i) = 0; (i) < (n); (i)++) cout << ans[i].second << ' ';
  cout << endl;
  return 0;
}
