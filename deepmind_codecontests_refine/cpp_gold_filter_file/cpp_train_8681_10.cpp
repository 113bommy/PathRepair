#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int cnt[N];
vector<pair<int, int> > f1(int n, vector<string> v) {
  vector<pair<int, int> > ans;
  for (int i = (0); i < (int)(n); ++i)
    for (int j = (0); j < (int)(n); ++j) {
      if (v[i][j] == '.') {
        ans.push_back(make_pair(i, j));
        break;
      }
    }
  return ans;
}
vector<pair<int, int> > f2(int n, vector<string> v) {
  vector<pair<int, int> > ans;
  for (int j = (0); j < (int)(n); ++j)
    for (int i = (0); i < (int)(n); ++i) {
      if (v[i][j] == '.') {
        ans.push_back(make_pair(i, j));
        break;
      }
    }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = (0); i < (int)(n); ++i) cin >> v[i];
  auto ans = f1(n, v);
  if (ans.size() < n) ans = f2(n, v);
  if (ans.size() < n) {
    cout << -1 << endl;
  } else {
    for (auto p : ans) {
      cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }
  }
}
