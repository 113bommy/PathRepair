#include <bits/stdc++.h>
using namespace std;
const double PI = 2 * acos(0.0);
const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";
template <class T>
ostream &operator<<(ostream &out, vector<T> &a) {
  out << "(";
  for (auto x : a) out << x << " ";
  return out << ")";
}
template <class T>
ostream &operator<<(ostream &out, pair<T, T> &a) {
  out << "(";
  cout << a.first << ", " << a.second;
  return out << ")";
}
void smain();
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  smain();
}
vector<int> di = {1, 1, -1, -1};
vector<int> dj = {1, -1, -1, 1};
vector<pair<int, int> > solve(int n) {
  vector<pair<int, int> > ret;
  if (n < 29) {
    int h = n >> 1;
    if (h == 0) h = 100;
    for (int i = 0; i < int(n); ++i) ret.push_back({i / h, i % h});
  } else {
    int l = (n - 5) / 4;
    vector<pair<int, int> > a = {{0, 0}};
    for (auto x : a) ret.push_back(x), n--;
    for (int i = 0; i < int(l); ++i)
      ret.push_back({0, i + 1}), ret.push_back({0, -i - 1}), n -= 2;
    for (int i = 0; n >= 2; ++i)
      ret.push_back({i + 1, 0}), ret.push_back({-i - 1, 0}), n -= 2;
    assert(n >= 0);
    while (n) ret.push_back({n--, 101100});
  }
  return ret;
}
bool check(vector<pair<int, int> > ans) {
  map<pair<int, int>, int> ret;
  vector<int> di = {1, 2, 2, 1, -1, -2, -2, -1};
  vector<int> dj = {-2, -1, 1, 2, 2, 1, -1, -2};
  queue<pair<int, int> > kek;
  for (auto x : ans) {
    cout << ("x") << " = " << x << endl;
    ;
    kek.push(x);
    if (ret.count(x)) {
      cout << ("x.first") << " = " << x.first << endl;
      ;
      cout << ("x.second") << " = " << x.second << endl;
      ;
      assert(0);
    }
    ret[x] = 4;
  }
  while (!kek.empty()) {
    pair<int, int> cur = kek.front();
    kek.pop();
    for (int dir = 0; dir < int(((int)(di.size()))); ++dir) {
      pair<int, int> nw = cur;
      nw.first += di[dir], nw.second += dj[dir];
      if (ret[nw] < 4) {
        ret[nw]++;
        if (ret[nw] == 4) kek.push(nw);
      }
    }
  }
  cout << ("ret.size()") << " = " << ret.size() << endl;
  ;
  int n = ans.size();
  cout << ("n * n / 10") << " = " << n * n / 10 << endl;
  ;
  cout << ("n") << " = " << n << endl;
  ;
  return ret.size() >= n * n / 10;
}
void smain() {
  int n;
  cin >> n;
  vector<pair<int, int> > ans = solve(n);
  for (auto x : ans) cout << x.first << " " << x.second << "\n";
}
