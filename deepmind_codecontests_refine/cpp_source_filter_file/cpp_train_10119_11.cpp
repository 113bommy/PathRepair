#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-5;
template <typename T>
T abs(const T& a) {
  if (a >= 0) return a;
  return -a;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    reverse(v[i].begin(), v[i].end());
  }
  vector<int> p(k);
  for (int i = 0; i < n; ++i) p[i] = i;
  int ans = INF;
  do {
    int curmi = INF, curma = 0;
    for (int i = 0; i < n; ++i) {
      int x = 0;
      for (int j = 0; j < k; ++j) {
        x = x * 10 + (v[i][p[j]] - '0');
      }
      curmi = min(x, curmi);
      curma = max(x, curma);
    }
    ans = min(ans, curma - curmi);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << '\n';
  return 0;
}
