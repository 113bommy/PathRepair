#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
constexpr auto PI = 3.14159265358979323846L;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
int a[100005];
int t1[2 * 100005 + 5];
int t2[2 * 100005 + 5];
void b(int n, int s, int e) {
  if (s == e) {
    t1[n] = a[s];
    t2[n] = 0;
  } else {
    int m = (s + e) / 2;
    if (m - s > 1 && (m - s) % 2 == 0) m++;
    b(2 * n, s, m);
    b(2 * n + 1, m + 1, e);
    if (t1[2 * n] + t1[2 * n + 1] >= 10)
      t2[n] = t2[2 * n] + t2[2 * n + 1] + 1;
    else
      t2[n] = t2[2 * n] + t2[2 * n + 1];
    t1[n] = (t1[2 * n] + t1[2 * n + 1]) % 10;
  }
}
pair<int, int> qq(int n, int s, int e, int l, int r) {
  if (r < s || l > e) return make_pair(0, 0);
  if (l <= s && e <= r) return (make_pair(t2[n], t1[n]));
  int m = (s + e) / 2;
  if (m - s > 1 && (m - s) % 2 == 0) m++;
  pair<int, int> p1 = qq(2 * n, s, m, l, r);
  pair<int, int> p2 = qq(2 * n + 1, m + 1, e, l, r);
  if (p1.second + p2.second >= 10)
    return (make_pair(p1.first + p2.first + 1, (p1.second + p2.second) % 10));
  else
    return (make_pair(p1.first + p2.first, (p1.second + p2.second) % 10));
}
int q(int n, int s, int e, int l, int r) {
  pair<int, int> p = qq(n, s, e, l, r);
  return p.first;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  b(1, 0, n - 1);
  int qu;
  cin >> qu;
  vector<int> ans(qu);
  pair<int, int> qq[qu];
  for (int i = 0; i < qu; i++) {
    int x, y;
    cin >> x >> y;
    qq[i] = make_pair(x, y);
  }
  for (int i = 0; i < qu; i++) {
    int x, y;
    x = qq[i].first;
    y = qq[i].second;
    if (x == y)
      ans[i] = 0;
    else if ((x - 1) % 2 == 0)
      ans[i] = q(1, 0, n - 1, x - 1, y - 1);
  }
  for (int i = 0; i < 2 * 100005 + 5; i++) t1[i] = 0, t2[i] = 0;
  if (n > 2) {
    b(1, 1, n - 2);
  }
  for (int i = 0; i < qu; i++) {
    int x, y;
    x = qq[i].first;
    y = qq[i].second;
    if ((x - 1) % 2 != 0) ans[i] = q(1, 1, n - 2, x - 1, y - 1);
  }
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
