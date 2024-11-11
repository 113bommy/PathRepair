#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-10;
const long double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  int a[1000010];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<pair<long double, int>> ans;
  for (int i = 0; i < n; i++) {
    int sz = 1;
    while (!ans.empty() and
           ans.back().first / ans.back().second > a[i] / (long double)sz) {
      a[i] += ans.back().first;
      sz += ans.back().second;
      ans.pop_back();
    }
    ans.push_back({a[i], sz});
  }
  cout << fixed << setprecision(12);
  for (auto a : ans) {
    for (int i = 0; i < a.second; i++) cout << a.first / a.second << '\n';
  }
  return 0;
}
