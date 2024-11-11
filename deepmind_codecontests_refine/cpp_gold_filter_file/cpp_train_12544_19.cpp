#include <bits/stdc++.h>
using namespace std;
void splitstr(const string &s, vector<string> &v) {
  istringstream in(s);
  copy(istream_iterator<string>(in), istream_iterator<string>(),
       back_inserter(v));
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
const int maxn = 20005;
const long long INF = (1e9) + 7;
const long double EPS = 1e-8;
vector<pair<pair<int, int>, int> > a[maxn];
vector<int> ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (int)n; i++) {
    int x, y;
    cin >> x >> y;
    int p = y / 1300;
    a[p].push_back(make_pair(make_pair(x, y), i + 1));
  }
  for (int i = 0; i < (int)maxn; i++) sort(a[i].begin(), a[i].end());
  for (int i = 0; i < (int)maxn; i++)
    for (int j = 0; j < (int)a[i].size(); j++) ans.push_back(a[i][j].second);
  for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
