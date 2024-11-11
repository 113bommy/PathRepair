#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
template <class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <size_t i, class T>
ostream& print_tuple_utils(ostream& out, const T& tup) {
  if constexpr (i == tuple_size<T>::value)
    return out << ")";
  else
    return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup),
                                       tup);
}
template <class... U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) {
  return print_tuple_utils<0, tuple<U...>>(out, tup);
}
template <class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type operator<<(
    ostream& out, const Con& container) {
  out << "{";
  for (auto it = container.begin(); it != container.end(); ++it)
    out << (it == container.begin() ? "" : ", ") << *it;
  return out << "}";
}
struct solver {
  int n, t;
  virtual void init() = 0;
  virtual int ask(int l, int r) = 0;
  virtual void answer(const vector<bool>& ans) = 0;
  void solve() {
    init();
    if (t == 0 or t == n) {
      answer(vector<bool>(n, !!t));
      return;
    }
    vector<bool> cur_xor(n);
    vector<bool> ans(n);
    auto upd_cur_xor = [&](int l, int r) {
      for (int i = (int)(l); i < (int)(r); ++i) cur_xor[i] = 1 - cur_xor[i];
    };
    function<int(int, int, int)> ask_til_diff_parity = [&](int l, int r,
                                                           int par) {
      assert((r - l + n) % 2 == 0);
      int new_t = ask(l, r);
      int diff = (new_t - t) & 1;
      if (0)
        cerr << "["
                "l"
                " = "
             << (l) << "] "
             << "["
                "r"
                " = "
             << (r) << "] "
             << "["
                "par"
                " = "
             << (par) << "] "
             << "["
                "diff"
                " = "
             << (diff) << "] "
             << "["
                "new_t"
                " = "
             << (new_t) << "] " << endl;
      if (diff == (r & 1)) {
        upd_cur_xor(0, r);
      } else {
        upd_cur_xor(l - 1, n);
      }
      if (diff == par) {
        return new_t;
      }
      t = new_t;
      return ask_til_diff_parity(l, r, par);
    };
    auto ask_til_left_flip = [&](int l, int r) {
      return ask_til_diff_parity(l, r, r & 1);
    };
    auto ask_til_right_flip = [&](int l, int r) {
      return ask_til_diff_parity(l, r, !(r & 1));
    };
    {
      int new_t = ask_til_right_flip(2, n);
      ans[0] = cur_xor[0] ^ ((new_t + t - (n - 1)) / 2);
      t = new_t;
      if (0)
        cerr << "["
                "ans[0]"
                " = "
             << (ans[0]) << "] " << endl;
    }
    for (int i = (int)(1); i < (int)(n); ++i) {
      int new_t = ask_til_left_flip(i + (~n & 1), i + 1);
      int sx = (new_t + t - (i + 1)) / 2;
      int px = (new_t ^ sx) & 1;
      if (0)
        cerr << "["
                "i"
                " = "
             << (i) << "] "
             << "["
                "sx"
                " = "
             << (sx) << "] "
             << "["
                "px"
                " = "
             << (px) << "] " << endl;
      ans[i] = cur_xor[i] ^ px;
      for (int f = (int)(0); f < (int)(i); ++f)
        ans[i] = ans[i] ^ cur_xor[f] ^ ans[f];
      t = new_t;
    }
    answer(ans);
  }
};
struct IOSolver : solver {
  void init() override { cin >> n >> t; }
  int ask(int l, int r) override {
    cout << "? " << l << ' ' << r << endl;
    int ans;
    cin >> ans;
    return ans;
  }
  void answer(const vector<bool>& ans) override {
    cout << "! ";
    for (auto i : ans) cout << i;
    cout << endl;
  }
};
struct AutoSolver : solver {
  string s, org;
  mt19937 rng;
  AutoSolver(bool from_file) {
    if (from_file) {
      ifstream inp("main.inp");
      inp >> rng;
      inp >> s;
    } else {
      ll seed = (ll)this ^ time(0);
      s = "";
      rng.seed(seed);
      n = (int)(rng() % 10 + 1);
      for (int i = (int)(0); i < (int)(n); ++i) s += char((rng() & 1) + '0');
      rng.seed(seed + 1);
      dump_state();
    }
  }
  AutoSolver(const string& s_, ll seed) : s(s_) {
    rng.seed(seed);
    dump_state();
  }
  void dump_state() {
    ofstream inp("main.inp");
    inp << rng << endl;
    inp << s << endl;
  }
  int cnt_query;
  void init() override {
    n = ((int)s.size());
    t = (int)count((s).begin(), (s).end(), '1');
    cout << s << ' '
         << "["
            "n"
            " = "
         << (n) << "] "
         << "["
            "t"
            " = "
         << (t) << "] " << endl;
    org = s;
    cnt_query = 40;
  }
  int ask(int l, int r) override {
    --cnt_query;
    if (cnt_query < 0) {
      cout << "Query exceed " << endl;
      exit(0);
    }
    cout << "? " << l << ' ' << r << endl;
    if (rng() & 1) {
      r = n;
    } else {
      l = 1;
    }
    for (int i = (int)(l - 1); i < (int)(r); ++i) {
      s[i] ^= 1;
    }
    int new_t = (int)count((s).begin(), (s).end(), '1');
    cout << s << ' '
         << "["
            "n"
            " = "
         << (n) << "] "
         << "["
            "new_t"
            " = "
         << (new_t) << "] " << endl;
    return new_t;
  }
  void answer(const vector<bool>& ans) override {
    cout << "! ";
    for (auto i : ans) {
      cout << i;
    }
    cout << endl;
    cout << "["
            "org"
            " = "
         << (org) << "] " << endl;
    assert(((int)ans.size()) == n);
    for (int i = (int)(0); i < (int)(n); ++i) {
      assert((org[i] & 1) == ans[i]);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  IOSolver().solve();
  return 0;
}
