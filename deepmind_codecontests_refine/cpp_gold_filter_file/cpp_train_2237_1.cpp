#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first * a.second != b.first * b.second)
    return a.first * a.second < b.first * b.second;
  return a.first < b.first;
}
struct rec {
  int n, m, hash;
  rec() {}
  bool operator<(const rec& a) const {
    if (n != a.n) return n < a.n;
    if (m != a.m) return m < a.m;
    return hash < a.hash;
  }
};
const int A = 1009;
rec get(vector<string>& s) {
  rec cur;
  cur.n = int((s).size()), cur.m = int((s[0]).size());
  cur.hash = 0;
  for (int i = 0; i < int(cur.n); ++i)
    for (int j = 0; j < int(cur.m); ++j) cur.hash = cur.hash * A + s[i][j];
  return cur;
}
void rot(vector<string>& s) {
  vector<string> res(int((s[0]).size()));
  for (int i = 0; i < int(int((res).size())); ++i)
    res[i].resize(int((s).size()), '.');
  for (int i = 0; i < int(int((s).size())); ++i)
    for (int j = 0; j < int(int((s[i]).size())); ++j) {
      res[int((s[i]).size()) - j - 1][i] = s[i][j];
    }
  s = res;
}
rec get(vector<string>& s, int i, int j, int n, int m) {
  vector<string> cur(n);
  for (int di = 0; di < int(n); ++di) {
    cur[di].resize(m, '.');
    for (int dj = 0; dj < int(m); ++dj) cur[di][dj] = s[i + di][j + dj];
  }
  rec ans = get(cur);
  for (int i = 0; i < int(3); ++i) {
    rot(cur);
    ans = min(ans, get(cur));
  }
  return ans;
}
int main() {
  int a, b;
  cin >> a >> b;
  vector<string> s(a);
  for (int i = 0; i < int(int((s).size())); ++i) cin >> s[i];
  vector<pair<int, int> > ok;
  for (int x = 1; x <= int(a); ++x)
    for (int y = 1; y <= int(b); ++y) {
      if (a % x == 0 && b % y == 0) {
        set<rec> cur;
        for (int i = 0; i < a; i += x)
          for (int j = 0; j < b; j += y) cur.insert(get(s, i, j, x, y));
        if (int((cur).size()) == (a / x) * (b / y)) {
          ok.push_back(make_pair(x, y));
        }
      }
    }
  sort((ok).begin(), (ok).end(), cmp);
  cout << int((ok).size()) << endl;
  cout << ok[0].first << " " << ok[0].second << endl;
  return 0;
}
