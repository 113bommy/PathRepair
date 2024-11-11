#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long int rand(long long int x, long long int y) {
  ++y;
  return (rng() % (y - x)) + x;
}
string to_string(char c) {
  string second(1, c);
  return second;
}
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void degug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void degug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  degug_out(T...);
}
inline long long int gcd(long long int a, long long int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  long long int n, x;
  cin >> n >> x;
  vector<pair<long long int, long long int> > pos;
  long long int neg;
  for (long long int i = (0); i <= (long long int)(n - 1); ++i) {
    long long int d, h;
    cin >> d >> h;
    neg = max(neg, d);
    if (d >= h) pos.emplace_back(d, h);
  }
  sort((pos).begin(), (pos).end(),
       [](pair<long long int, long long int> x,
          pair<long long int, long long int> y) {
         return x.first - x.second > y.first - y.second;
       });
  if (pos.empty() || pos[0].first - pos[0].second == 0) {
    if (x <= neg)
      cout << 1 << '\n';
    else
      cout << "-1\n";
    return;
  }
  long long int st = -1, en = 1e9 + 1000, mid = 0;
  while (en - st > 1) {
    mid = (st + en) >> 1;
    if (mid * (pos[0].first - pos[0].second) + neg >= x)
      en = mid;
    else
      st = mid;
  }
  if (en != 1e9 + 1000)
    cout << en + 1 << '\n';
  else
    cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
