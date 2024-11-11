#include <bits/stdc++.h>
using namespace std;
int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();
long long MAX_LL = numeric_limits<long long>::max();
long long MIN_LL = numeric_limits<long long>::min();
int n;
string seq;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
template <typename T, typename U>
std::pair<T, U> operator-(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first - r.first, l.second - r.second};
}
map<char, pair<long long, long long>> key;
vector<pair<long long, long long>> pref, suf;
long long res = MAX_LL;
bool is_possible(pair<long long, long long> p1, pair<long long, long long> p2,
                 int m) {
  pair<long long, long long> r = p1 - p2;
  return ((abs(r.first) + abs(r.second) <= m) &&
          (abs(r.first + r.second) % 2 == m % 2));
}
void solve(long long a, long long b) {
  if (a > b) return;
  long long pa = a;
  long long pb = b;
  while (pb <= n && !is_possible(pref[pa], suf[pb], pb - pa)) {
    pa++;
    pb++;
  }
  if (pb <= n) {
    res = min(res, pb - pa);
    solve(pa, pb - 2);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> seq;
  long long x, y;
  cin >> x >> y;
  key['U'] = {0, 1};
  key['D'] = {0, -1};
  key['L'] = {-1, 0};
  key['R'] = {1, 0};
  pref.resize(n + 1);
  suf.resize(n + 1);
  pref[0] = {0, 0};
  suf[n] = {x, y};
  for (int i = 1; i < n + 1; i++) {
    pref[i] = pref[n - 1] + key[seq[i - 1]];
    suf[n - i] = suf[n - i + 1] - key[seq[n - i]];
  }
  if (pref[n] == suf[n]) {
    cout << 0 << endl;
    return 0;
  }
  solve(0, n);
  solve(0, n - 1);
  if (res == MAX_LL)
    cout << -1 << endl;
  else
    cout << res << endl;
}
