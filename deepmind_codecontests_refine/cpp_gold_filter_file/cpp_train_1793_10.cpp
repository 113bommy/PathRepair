#include <bits/stdc++.h>
using namespace std;
int inf = 1 << 30;
long long linf = (long long)1 << 62;
pair<int, int> verify(int val, vector<vector<int> >& data) {
  vector<int> idx(1 << data[0].size(), -1);
  int mask = 1 << data[0].size();
  mask--;
  for (int k = 0; k < data.size(); k++) {
    auto v = data[k];
    int currentmask = 0;
    for (int i = 0; i < v.size(); i++) {
      currentmask |= (v[i] >= val) << i;
    }
    idx[currentmask] = k + 1;
  }
  for (int i = 0; i < idx.size(); i++) {
    for (int j = 0; j < idx.size(); j++) {
      if ((i | j) == mask && idx[i] != -1 && idx[j] != -1) {
        return {idx[i], idx[j]};
      }
    }
  }
  return {-1, -1};
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > data(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data[i][j];
    }
  }
  int lo = 0, hi = inf;
  int mid;
  while (lo < hi) {
    mid = lo + (hi - lo + 1) / 2;
    auto res = verify(mid, data);
    ;
    if (res.first != -1) {
      lo = mid;
      ;
    } else {
      ;
      hi = mid - 1;
    }
  }
  auto res = verify(lo, data);
  cout << res.first << " " << res.second << endl;
}
