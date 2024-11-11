#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class T>
void PV(T a, T b) {
  while (a != b) cout << *a++, cout << (a != b ? " " : "\n");
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
string tostring(T first, int len = 0) {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), '0') + r;
  return r;
}
template <class T>
void convert(string first, T &r) {
  stringstream ss(first);
  ss >> r;
}
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 7001;
int n, m;
vector<pair<pair<int, int>, int> > level[N];
int c[1000010];
void init() {
  c[1] = 1;
  for (int i = 2; i < 1000010; i++) {
    if (i & (i - 1))
      c[i] = c[i - 1] + 1;
    else
      c[i] = c[i - 1] + 2;
  }
}
int main() {
  cin >> n >> m;
  init();
  while (m--) {
    int op;
    cin >> op;
    if (op == 1) {
      int lev, l, r, first;
      cin >> lev >> l >> r >> first;
      level[lev].push_back(make_pair(make_pair(l, r), first));
    } else {
      int lev, pos;
      cin >> lev >> pos;
      vector<int> v;
      int l = pos, r = pos;
      for (int j = lev; j <= n; j++) {
        for (auto i : level[j]) {
          int left = i.first.first;
          int right = i.first.second;
          if (left > r || right < l) continue;
          v.push_back(i.second);
        }
        l = c[l];
        r = c[r + 1] - 1;
      }
      sort((v).begin(), (v).end()),
          v.resize(unique((v).begin(), (v).end()) - v.begin());
      cout << v.size() << endl;
    }
  }
  return 0;
}
