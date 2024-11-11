#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d, m;
  cin >> d >> m;
  vector<int> gen(d);
  for (int i = 0; i < d; i++) {
    cin >> gen[i];
  }
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  const int MAX = 30010;
  struct State {
    bitset<MAX> left;
    bitset<MAX> right;
    long long len;
    long long res;
  };
  auto dbg = [&](const State& a) {
    for (int i = 1; i < n; i++) cerr << a.left[i];
    cerr << " ";
    for (int i = 1; i < n; i++) cerr << a.right[i];
    cerr << " ";
    cerr << a.len << " " << a.res << '\n';
  };
  bitset<MAX> all;
  for (int i = 1; i < n; i++) all.set(i);
  auto Unite = [&](const State& a, const State& b) -> State {
    State c;
    c.len = a.len + b.len;
    c.res = a.res + b.res;
    c.left = a.left;
    c.right = b.right;
    if (a.len < n - 1) {
      c.left &= (b.left >> a.len) | (all << (n - 1 - a.len));
    }
    if (b.len < n - 1) {
      c.right &= (a.right << b.len) | (all >> (n - 1 - b.len));
    }
    if (a.len + b.len >= n) {
      bitset<MAX> d = a.right & b.left;
      if (a.len < n - 1) {
        d &= (all >> (n - 1 - a.len));
      }
      if (b.len < n - 1) {
        d &= (all << (n - 1 - b.len));
      }
      c.res += d.count();
    }
    return c;
  };
  auto calc = [&](long long up) -> long long {
    if (up < n) {
      return 0;
    }
    vector<vector<State>> states(1, vector<State>(m));
    for (int i = 0; i < m; i++) {
      states[0][i].len = 1;
      if (n == 1) {
        states[0][i].res = b[0] >= i;
      } else {
        for (int j = 1; j < n; j++) {
          if (b[j] >= i) {
            states[0][i].left.set(j);
          }
        }
        for (int j = 1; j < n; j++) {
          if (b[j - 1] >= i) {
            states[0][i].right.set(j);
          }
        }
      }
    }
    long long z = 1;
    while (z <= up / d) {
      int sz = (int)states.size();
      states.resize(sz + 1);
      states[sz].resize(m);
      for (int i = 0; i < m; i++) {
        State cur = states[sz - 1][i];
        for (int j = 1; j < d; j++) {
          cur = Unite(cur, states[sz - 1][(i + gen[j]) % m]);
        }
        states[sz][i] = cur;
      }
      z *= d;
    }
    State res;
    int any = 0;
    int shift = 0;
    for (int i = (int)states.size() - 1; i >= 0; i--) {
      z = 1;
      for (int j = 0; j < i; j++) {
        z *= d;
      }
      for (int j = 0; j < m; j++) {
        if (up >= z) {
          if (!any)
            res = states[i][(shift + gen[j]) % m];
          else
            res = Unite(res, states[i][(shift + gen[j]) % m]);
          any = 1;
          up -= z;
        } else {
          shift = (shift + gen[j]) % m;
          break;
        }
      }
    }
    return res.res;
  };
  long long L, R;
  cin >> L >> R;
  cout << calc(R) - calc(L + n - 2) << '\n';
  return 0;
}
