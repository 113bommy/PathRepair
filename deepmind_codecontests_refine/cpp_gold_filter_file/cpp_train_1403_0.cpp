#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);
bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main(void) {
  ios_base::sync_with_stdio(false);
  int n, days, x, curr = 0;
  vector<int> res;
  vector<pair<int, int> > a;
  cin >> n >> days;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    a.push_back(make_pair(x, i));
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < a.size(); i++) {
    if (curr + a[i].first <= days) {
      curr += a[i].first;
      res.push_back(a[i].second);
    }
  }
  if (!res.size())
    cout << 0;
  else {
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
  }
  return (0);
}
