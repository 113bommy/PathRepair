#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using i64 = int64_t;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& pr) {
  os << pr.first << " " << pr.second;
  return os;
}
template <class T1>
ostream& operator<<(ostream& os, const vector<T1>& v) {
  for (auto it = v.begin(); it != v.end(); it++) os << (*it) << " ";
  return os;
}
template <class T1>
ostream& operator<<(ostream& os, const set<T1>& s) {
  for (auto it = s.begin(); it != s.end(); it++) os << (*it) << " ";
  return os;
}
template <class T1>
ostream& operator<<(ostream& os, const vector<vector<T1>>& v) {
  for (vector<T1> u : v) {
    for (T1 i : u) cout << i << " ";
    cout << endl;
  }
  return os;
}
template <class T1, class T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T1>
istream& operator>>(istream& is, vector<T1>& v) {
  for (auto& x : v) is >> x;
  return is;
}
istream& operator>>(istream& is, string& s) {
  getline(is, s);
  return is;
}
void __print(int x) { cerr << x; }
template <class T>
using max_heap = priority_queue<T>;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
class SSTree {
 public:
  size_t size;
  T dflt;
  vector<T> t, lz;
  T (*cmb)(T, T);
  SSTree(size_t n, T d, T (*cmb)(T, T)) : size(n), dflt(d), cmb(cmb) {
    t.assign(2 * n, d);
    lz.assign(2 * n, d);
  }
  void build(vector<T> v) {
    int i;
    for (i = 0; i < size; i++) t[size + i] = v[i];
    for (i = size - 1; i > 0; i--) t[i] = cmb(t[i << 1], t[i << 1 | 1]);
  }
  T rangeQuery(int l, int r) {
    T ret = 0;
    for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ret = cmb(ret, t[l++]);
      if (!(r & 1)) ret = cmb(ret, t[r--]);
    }
    return ret;
  }
  T pointQuery(int q) {
    q += size;
    T ret = 0;
    while (q) {
      ret = cmb(ret, t[q]);
      q >>= 1;
    }
    return ret;
  }
  void rangeUpdate(int l, int r, T v) {
    for (l += size, r += size; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) {
        t[l] = cmb(t[l], v);
        l++;
      }
      if (!(r & 1)) {
        t[r] = cmb(t[r], v);
        r--;
      }
    }
  }
  void pointUpdate(int i, int v) {
    i += size;
    t[i] = v;
    while (i) {
      i >>= 1;
      t[i] = cmb(t[i << 1], t[i << 1 | 1]);
    }
  }
};
unsigned int nextPowerOf2(unsigned int n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}
void solve() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int nodd = 0, neven = 0;
    set<int> oddpos, evepos, s1, s2;
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 0) {
        neven++;
        evepos.insert(i);
      } else {
        nodd++;
        oddpos.insert(i);
      }
    }
    s1 = oddpos;
    s2 = evepos;
    if (abs(nodd - neven) > 1)
      cout << -1 << endl;
    else {
      int bst = 1e9, ans = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (i & 1) {
          if (oddpos.find(i) != oddpos.end())
            continue;
          else {
            auto it = oddpos.lower_bound(i);
            if (it == oddpos.end())
              ok = false;
            else {
              ans += ((*it) - i);
              oddpos.erase(it);
              evepos.insert(*it);
            }
          }
        } else {
          auto it = evepos.lower_bound(i);
          if (it == evepos.end())
            ok = false;
          else {
            ans += ((*it) - i);
            evepos.erase(it);
            oddpos.insert(*it);
          }
        }
      }
      if (ok) bst = min(bst, ans);
      ok = true;
      ans = 0;
      oddpos = s1;
      evepos = s2;
      for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
          if (oddpos.find(i) != oddpos.end())
            continue;
          else {
            auto it = oddpos.lower_bound(i);
            if (it == oddpos.end())
              ok = false;
            else {
              ans += ((*it) - i);
              oddpos.erase(it);
              evepos.insert(*it);
            }
          }
        } else {
          auto it = evepos.lower_bound(i);
          if (it == evepos.end())
            ok = false;
          else {
            ans += ((*it) - i);
            evepos.erase(it);
            oddpos.insert(*it);
          }
        }
      }
      if (ok) bst = min(bst, ans);
      cout << bst << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  auto clk_strt = chrono::high_resolution_clock::now();
  solve();
  auto clk_end = chrono::high_resolution_clock::now();
  ;
  return 0;
}
