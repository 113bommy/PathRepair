#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 123;
const int INF = (int)1e9 + 123;
const double eps = 1e-6;
int n, m, ans;
pair<int, int> a[N], b[N];
pair<int, int> vector_of_movement(pair<int, int> a, pair<int, int> b) {
  pair<int, int> c;
  c = make_pair(b.first - a.first, b.second - a.second);
  return c;
}
bool will_she_be_wet(pair<int, int> a, pair<int, int> b) {
  if (a.first != 0) {
    return ((a.first / abs(a.first)) == (b.second / abs(b.second)));
  } else {
    return ((a.second / abs(a.second)) != (b.first / abs(b.first)));
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  m = n - 1;
  for (int i = 1; i < n; i++) {
    b[i] = vector_of_movement(a[i], a[i + 1]);
  }
  for (int i = 1; i <= m - 1; i++) {
    ans += will_she_be_wet(b[i], b[i + 1]);
  }
  cout << ans;
  return 0;
}
