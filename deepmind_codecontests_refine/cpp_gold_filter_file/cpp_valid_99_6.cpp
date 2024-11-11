#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
inline int ceili(int x, int y) { return (x + y - 1) / y; }
inline long long ceili(long long x, long long y) { return (x + y - 1) / y; }
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{  ";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[  ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  vector<int> idx;
  for (int i = (0); i < (int)(n); ++i)
    if (str[i] == '2') idx.push_back(i);
  int ntwo = ((int)((idx).size()));
  if (ntwo == 1 || ntwo == 2) {
    cout << "NO"
         << "\n";
    return;
  }
  vector<string> ans(n, string(n, '='));
  for (int i = (0); i < (int)(n); ++i) ans[i][i] = 'X';
  ;
  for (int i = (0); i < (int)(ntwo); ++i) {
    int x = idx[i], y = idx[(i + 1) % ntwo];
    ans[x][y] = '+';
    ans[y][x] = '-';
  }
  cout << "YES"
       << "\n";
  for (int i = (0); i < (int)(n); ++i) cout << ans[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
