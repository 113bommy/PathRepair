#include <bits/stdc++.h>
using namespace std;
template <class Ta, class Tb>
inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
};
const double EPS = 1e-9;
const int INF = 1000000000;
const int MOD = 1000000007;
const int diri[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dirj[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dico1(const vector<int>& v, int p) {
  int r = v.size();
  int e = 0, d = v.size() - 1;
  while (e <= d) {
    int m = (e + d) / 2;
    if (v[m] > p) {
      r = m;
      d = m - 1;
    } else
      e = m + 1;
  }
  return r;
}
int dico2(const vector<int>& v, int p) {
  int r = -1;
  int e = 0, d = v.size() - 1;
  while (e <= d) {
    int m = (e + d) / 2;
    if (v[m] < p) {
      r = m;
      e = m + 1;
    } else
      d = m - 1;
  }
  return r;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > web(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    web[i] = vector<int>(k);
    for (int j = 0; j < k; ++j) cin >> web[i][j];
    sort(web[i].begin(), web[i].end());
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a = (i + n - 1) % n;
    int b = (i + 1) % n;
    for (int j = 0; j + 1 < web[i].size(); ++j) {
      int h1 = web[i][j], h2 = web[i][j + 1];
      int ta = dico2(web[a], h2) - dico1(web[a], h1) + 1;
      int tb = dico2(web[b], h2) - dico1(web[b], h1) + 1;
      if (ta != tb) ++res;
    }
  }
  cout << res << endl;
}
