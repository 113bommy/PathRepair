#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (auto& i : arr) {
    in >> i;
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> arr) {
  for (int64_t i = 0; i < (int64_t)arr.size() - 1; ++i) out << arr[i] << " ";
  if (arr.size()) out << arr.back();
  out << endl;
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, set<T>& s) {
  for (auto x : s) out << x << " ";
  out << endl;
  return out;
}
const int64_t INF = 1e18;
struct seg_tr {
  int64_t l, r;
  seg_tr* lch;
  seg_tr* rch;
  int64_t mn;
  int64_t mod;
  seg_tr(int64_t L, int64_t R) {
    l = L;
    r = R;
    if (l == r - 1) {
      lch = nullptr;
      rch = nullptr;
      mn = 1;
      mod = -1;
    } else {
      int64_t m = (r + l) / 2;
      lch = new seg_tr(l, m);
      rch = new seg_tr(m, r);
      mn = 1;
      mod = -1;
    }
  }
  void upd(int64_t L, int64_t R, int64_t val) {
    if (l >= R || L >= r) {
      return;
    } else if (l >= L && r <= R) {
      mod = val;
    } else {
      lch->upd(L, R, val);
      rch->upd(L, R, val);
    }
  }
  int64_t get(int64_t id) {
    if (id < l || id >= r) {
      return -INF;
    } else if (l == r - 1) {
      return max(mn, mod);
    } else {
      return max(mod, max(rch->get(id), lch->get(id)));
    }
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t n;
  cin >> n;
  string ans;
  int64_t x = 1, y = 1;
  for (int64_t i = 0; i < n - 1; ++i) {
    cout << "? " << x + 1 << " " << y << " " << n << " " << n << endl;
    string s;
    cin >> s;
    if (s == "BAD")
      return 0;
    else if (s == "YES") {
      x++;
      ans.push_back('D');
    } else {
      y++;
      ans.push_back('R');
    }
  }
  x = n;
  y = n;
  for (int64_t i = 0; i < n - 1; ++i) {
    cout << "? " << 1 << " " << 1 << " " << x << " " << y - 1 << endl;
    string s;
    cin >> s;
    if (s == "YES") {
      y--;
      ans.push_back('R');
    } else {
      x--;
      ans.push_back('D');
    }
  }
  reverse(ans.begin() + n - 1, ans.end());
  cout << "! " << ans << endl;
  return 0;
}
