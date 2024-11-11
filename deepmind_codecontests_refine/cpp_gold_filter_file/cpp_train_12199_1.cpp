#include <bits/stdc++.h>
using namespace std;
struct Arrete {
  int v, c;
};
struct Point {
  int x, y;
  double distance(Point other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
  }
};
const int MAXN = 2e5;
int from_l[MAXN], from_r[MAXN];
string s, t;
int N, M;
bool can(int sz) {
  for (int i(0); i + sz - 1 < N; ++i)
    if (from_l[i] > from_r[i + sz - 1]) return true;
  return false;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  N = s.size();
  M = t.size();
  int i(0), j(0);
  while (i < N) {
    from_l[i] = j;
    if (j < M && s[i] == t[j]) ++j;
    ++i;
  }
  i = N - 1;
  j = M - 1;
  while (i >= 0) {
    from_r[i] = j;
    if (j >= 0 && s[i] == t[j]) --j;
    --i;
  }
  long long l(0), r(N - 1);
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (can(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}
