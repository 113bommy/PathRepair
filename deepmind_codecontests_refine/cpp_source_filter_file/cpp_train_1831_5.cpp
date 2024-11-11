#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) + 20;
const long long INFll = 1ll * int(1e9) * int(1e9);
const int MOD = 1000000007;
template <typename T, typename Q>
ostream& operator<<(ostream& out, pair<T, Q>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename Q>
istream& operator>>(istream& in, pair<T, Q>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
  return out;
}
bool in(int x, int y, int x1, int y1, int x2, int y2) {
  if (x * 1ll * y1 > x1 * 1ll * y && x * 1ll * y2 <= x2 * 1ll * y) return true;
  return false;
}
int solve(int x, int y, int p, int q) {
  int l = 1, r = INF;
  int ans = INF;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (q * 1ll * mid < y) {
      l = mid + 1;
      continue;
    }
    long long delta = q * 1ll * mid - y;
    if (p * 1ll * mid - x > delta || p * 1ll * mid - x < 0)
      l = mid + 1;
    else {
      ans = min((long long)ans, delta);
      r = mid - 1;
    }
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(5));
  cin >> a;
  vector<int> p(6);
  int ans = MOD + 1;
  vector<int> k(5);
  for (int j = 0; j < 5; ++j)
    for (int i = 0; i < n; ++i)
      if (a[i][j] != -1) k[j]++;
  while (!p.back()) {
    int mx = 0;
    for (int j = 0; j < 5; ++j) {
      int q2 = (1 << p[j]);
      int q1 = (1 << (p[j] + 1));
      if (p[j] == 5) q1 = 1;
      int p2 = 1;
      int p1 = p[j] == 5 ? -1 : 1;
      if (!in(k[j], n, p1, q1, p2, q2))
        mx = max(mx, min(solve(k[j], n, p1, q1) + 1, solve(k[j], n, p2, q2)));
    }
    int sum = 0;
    bool good = 1;
    for (int j = 0; j < 5; ++j) {
      int q2 = (1 << p[j]);
      int q1 = (1 << (p[j] + 1));
      if (p[j] == 5) q1 = 1;
      int p2 = 1;
      int p1 = p[j] == 5 ? -1 : 1;
      if (!in(k[j], n + mx, p1, q1, p2, q2) && a[0][j] == -1)
        good = 0;
      else {
        int pts = 500 * (p[j] + 1);
        if (a[0][j] != -1) sum += pts - pts * a[0][j] / 250;
        if (a[1][j] != -1) sum -= pts - pts * a[1][j] / 250;
      }
    }
    if (sum < 0) good = 0;
    if (good) ans = min(ans, mx);
    int j = 0;
    while (p[j] == 5) p[j++] = 0;
    p[j]++;
  }
  if (ans == MOD + 1)
    cout << "-1\n";
  else
    cout << ans << endl;
  if (0)
    cerr << fixed << setprecision(0)
         << "TIME = " << clock() / (long double)CLOCKS_PER_SEC * 1000 << "\n";
  return 0;
}
