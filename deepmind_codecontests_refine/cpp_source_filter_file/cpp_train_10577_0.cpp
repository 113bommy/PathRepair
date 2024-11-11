#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool MinPlace(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
class cnt {
 public:
  int a, b, c, d;
  cnt(int a, int b, int c, int d) : a(a), b(b), c(c), d(d){};
  cnt(const cnt &o) : a(o.a), b(o.b), c(o.c), d(o.d){};
  cnt() : a(0), b(0), c(0), d(0){};
  cnt operator+(const cnt &o) const {
    return cnt(a + o.a, b + o.b, c + o.c, d + o.d);
  }
  cnt operator-(const cnt &o) const {
    return cnt(a - o.a, b - o.b, c - o.c, d - o.d);
  }
  cnt &operator+=(const cnt &o) {
    a += o.a;
    b += o.b;
    c += o.c;
    d += o.d;
    return *this;
  }
  cnt(char ch) {
    a = (ch == 'A');
    b = (ch == 'C');
    c = (ch == 'T');
    d = (ch == 'G');
  }
  cnt operator-() { return cnt(-a, -b, -c, -d); }
};
template <typename T = long long int>
class BIT {
  int n;
  vector<T> v;

 public:
  BIT(int n) : n(n) { v.resize(n + 1); }
  void inc(int pos, T delta) {
    for (int i = pos; i <= n; i += i & (-i)) v[i] += delta;
  }
  void dec(int pos, T delta) { inc(pos, -delta); }
  T qry(int r) {
    T ret;
    for (int i = r; i; i = i & (i - 1)) ret += v[i];
    return ret;
  }
  T rangeQry(int l, int r) { return qry(r) - qry(l - 1); }
  void upd(int pos, T val) { inc(pos, val - pointQry(pos)); }
  T pointQry(int pos) { return qry(pos) - qry(pos - 1); }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  string s;
  cin >> s >> q;
  int n = s.size();
  vector<vector<BIT<cnt>>> all(10, vector<BIT<cnt>>(10, BIT<cnt>(1)));
  vector<vector<pair<int, pair<int, int>>>> loc(
      n + 1, vector<pair<int, pair<int, int>>>());
  for (int i = 0; i < min(n, 10); i++) {
    for (int j = 0; j < 10; j++) {
      all[i][j] = BIT<cnt>((n + 2 * j + 1) / (j + 1));
      for (int k = i, pos = 1; k < n; k += (j + 1), pos++) {
        all[i][j].inc(pos, cnt(s[k]));
        loc[k].push_back(make_pair(i, make_pair(j, pos)));
      }
    }
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      char ch;
      cin >> x >> ch;
      x--;
      for (auto l : loc[x])
        all[l.first][l.second.first].inc(l.second.second, cnt(ch) - cnt(s[x]));
      s[x] = ch;
    } else {
      int l, r;
      string e;
      cin >> l >> r >> e;
      l--;
      r--;
      int j = int(e.size()) - 1, val = 0;
      for (int i = 0; i <= min(j, r - l); i++) {
        int start = (l + i) % 10;
        cnt lookup = all[start][j].rangeQry((l + i - start) / (j + 1) + 1,
                                            (r - start) / (j + 1) + 1);
        switch (e[i]) {
          case 'A':
            val += lookup.a;
            break;
          case 'C':
            val += lookup.b;
            break;
          case 'T':
            val += lookup.c;
            break;
          case 'G':
            val += lookup.d;
            break;
        }
      }
      cout << val << "\n";
    }
  }
};
