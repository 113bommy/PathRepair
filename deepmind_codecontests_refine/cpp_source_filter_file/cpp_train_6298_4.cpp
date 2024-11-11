#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, k, a, b, c;
  long long ans;
  cin >> m >> m >> k;
  vector<tuple<int, int, int>> v;
  vector<int> q;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    v.push_back(make_tuple(a, b, c));
  }
  for (int i = 1; i <= k; i++) {
    cin >> a;
    q.push_back(a);
  }
  for (auto a : v) {
    for (auto p : q) {
      if (get<0>(a) <= p && p <= get<1>(a)) ans += p + get<2>(a) - get<0>(a);
    }
  }
  cout << ans;
  return 0;
}
