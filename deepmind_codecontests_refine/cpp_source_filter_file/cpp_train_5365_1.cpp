#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v;
map<pair<long long, long long>, int> m;
map<pair<long long, long long>, int>::iterator it;
int main() {
  int n;
  int x, y;
  long long res;
  while (cin >> n) {
    v.clear();
    m.clear();
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (i != j)
          m[make_pair(v[i].first - v[j].first, v[i].second - v[j].second)]++;
      }
    }
    res = 0;
    long long temp;
    for (it = m.begin(); it != m.end(); it++) {
      temp = (*it).second;
      res += (temp * (temp - 1)) / 2;
    }
    cout << res / 2 << '\n';
  }
  return 0;
}
