#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const int inf = (int)1e9;
const long double eps = 1e-12;
const int M = 400;
const int N = 100001;
const long long P = (long long)1e9 + 7;
const int K = 11;
int w[300];
int main() {
  int m, t, r;
  cin >> m >> t >> r;
  vector<int> a;
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> w[i];
    vector<int> aa;
    for (int j = 0; j < (int)a.size(); ++j)
      if (a[j] + t >= w[i]) aa.push_back(a[j]);
    if (i > 0 && r - (int)aa.size() > w[i] - w[i - 1]) {
      cout << -1;
      return 0;
    }
    for (int j = 1;
         (int)aa.size() < r && j < t && w[i] - j >= (i == 0 ? -inf : w[i - 1]);
         ++j) {
      aa.push_back(w[i] - j);
      ++ans;
    }
    if ((int)aa.size() < r) {
      cout << -1;
      return 0;
    }
    a = aa;
  }
  cout << ans;
  return 0;
}
