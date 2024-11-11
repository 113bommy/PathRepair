#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = mod * mod;
const long double eps = 1e-6;
const long double pi = acos(-1.0);
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int le = i;
    while (i + 1 < n && a[i] == a[i + 1]) i++;
    int cnt = i - le + 1;
    v.push_back({cnt, a[i]});
  }
  sort(v.begin(), v.end(), greater<pair<int, int>>());
  int sup = v[0].first;
  vector<int> rv(v.size() + 1);
  for (int i = 0; i < v.size(); i++) {
    rv[i + 1] = rv[i] + v[i].first;
  }
  int loc = 0;
  int ma = 0;
  int chk, chk2;
  for (long long h = n; h >= 1; h--) {
    while (loc < v.size() && v[loc].first > h) {
      loc++;
    }
    int sum = loc * h + n - rv[loc];
    if (h * h > sum) continue;
    long long num = h * (sum / h);
    if (ma < num) {
      chk = h;
      chk2 = sum / h;
      ma = num;
    }
  }
  int h = chk;
  int w = chk2;
  a.clear();
  for (int i = 0; i < v.size(); i++) {
    v[i].first = min(v[i].first, h);
    for (int j = 0; j < v[i].first; j++) {
      a.push_back(v[i].second);
    }
  }
  vector<vector<int>> ans(h);
  for (int i = 0; i < h; i++) {
    ans[i].resize(w);
  }
  int tmp = 0;
  for (int j = 0; j < w; j++) {
    for (int i = 0; i < h; i++) {
      int val = a[tmp];
      tmp++;
      int x = i;
      int y = (i + j) % w;
      ans[x][y] = val;
    }
  }
  cout << h * w << endl;
  cout << h << " " << w << endl;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j > 0) cout << " ";
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
