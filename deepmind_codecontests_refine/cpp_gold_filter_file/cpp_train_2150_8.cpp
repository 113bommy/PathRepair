#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& p) {
  return o << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& o, const vector<T>& vc) {
  o << "{";
  for (const T& v : vc) o << v << ",";
  o << "}";
  return o;
}
using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
using P = pair<int, int>;
ll solve(V<P> ps) {
  int N = ps.size();
  const int MX = 100010, inf = 1e8;
  V<int> Down(MX + MX + 1, inf), Up(MX + MX + 1, -inf);
  {
    V<int> d(MX + MX + 1, -inf);
    for (P p : ps) {
      p.second--;
      int X = (p.first - p.second) / 2, Y = (p.first + p.second) / 2;
      d[X + MX] = max(d[X + MX], Y);
    }
    for (int i = 0; i < (int)(MX + MX); i++) d[i + 1] = max(d[i + 1], d[i]);
    for (int i = 0; i < (int)(MX + MX + 1); i++) Down[i] = min(Down[i], d[i]);
  }
  {
    V<int> d(MX + MX + 1, -inf);
    for (P p : ps) {
      p.first--;
      int X = (p.first - p.second) / 2, Y = (p.first + p.second) / 2;
      d[X + MX] = max(d[X + MX], Y);
    }
    reverse(d.begin(), d.end());
    for (int i = 0; i < (int)(MX + MX); i++) d[i + 1] = max(d[i + 1], d[i]);
    reverse(d.begin(), d.end());
    for (int i = 0; i < (int)(MX + MX + 1); i++) Down[i] = min(Down[i], d[i]);
  }
  {
    V<int> u(MX + MX + 1, inf);
    for (P p : ps) {
      p.second++;
      int X = (p.first - p.second) / 2, Y = (p.first + p.second) / 2;
      u[X + MX] = min(u[X + MX], Y);
    }
    reverse(u.begin(), u.end());
    for (int i = 0; i < (int)(MX + MX); i++) u[i + 1] = min(u[i + 1], u[i]);
    reverse(u.begin(), u.end());
    for (int i = 0; i < (int)(MX + MX + 1); i++) Up[i] = max(Up[i], u[i]);
  }
  {
    V<int> u(MX + MX + 1, inf);
    for (P p : ps) {
      p.first++;
      int X = (p.first - p.second) / 2, Y = (p.first + p.second) / 2;
      u[X + MX] = min(u[X + MX], Y);
    }
    for (int i = 0; i < (int)(MX + MX); i++) u[i + 1] = min(u[i + 1], u[i]);
    for (int i = 0; i < (int)(MX + MX + 1); i++) Up[i] = max(Up[i], u[i]);
  }
  ll ans = 0;
  for (int i = 0; i < (int)(MX + MX + 1); i++) {
    ans += max(Down[i] - Up[i] + 1, 0);
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int N;
  cin >> N;
  V<P> o, e;
  for (int i = 0; i < (int)(N); i++) {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 0)
      e.push_back(P(x + 1, y));
    else
      o.push_back(P(x, y));
  }
  cout << solve(o) + solve(e) << endl;
}
