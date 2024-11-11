#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
template <typename T, size_t N>
int SIZE(const T (&t)[N]) {
  return N;
}
template <typename T>
int SIZE(const T &t) {
  return t.size();
}
string to_string(const string s, int x1 = 0, int x2 = 1e9) {
  return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"';
}
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9) {
  string t = "";
  for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1);
       __iii__ <= __jjj__; ++__iii__) {
    t += b[__iii__] + '0';
  }
  return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p) {
  l_v_l_v_l++;
  string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
  l_v_l_v_l--;
  return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords) {
  int rnk = rank<A>::value;
  string tab(t_a_b_s, ' ');
  string res = "";
  bool first = true;
  if (l_v_l_v_l == 0) res += '\n';
  res += tab + "[";
  x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
  auto l = begin(v);
  advance(l, x1);
  auto r = l;
  advance(r, (x2 - x1) + (x2 < SIZE(v)));
  for (auto e = l; e != r; e = next(e)) {
    if (!first) {
      res += ", ";
    }
    first = false;
    l_v_l_v_l++;
    if (e != l) {
      if (rnk > 1) {
        res += '\n';
        t_a_b_s = l_v_l_v_l;
      };
    } else {
      t_a_b_s = 0;
    }
    res += to_string(*e, coords...);
    l_v_l_v_l--;
  }
  res += "]";
  if (l_v_l_v_l == 0) res += '\n';
  return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T) {
  cerr << to_string(H) << " | ";
  dbgm(T...);
}
long long mod = 1e9 + 7;
void print(vector<long long> &a) {
  sort(a.begin(), a.end());
  cout << a.size() << "\n";
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr << "...............Console is yours! :)................."
       << "\n";
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n <= 1) {
    cout << -1 << "\n";
    return 0;
  }
  sort(a.begin(), a.end());
  vector<long long> ans;
  if (n == 2) {
    if (a[0] == a[1])
      ans.push_back(a[0]);
    else if (abs(a[0] - a[1]) % 2 == 1) {
      long long d = a[1] - a[0];
      ans.push_back(a[1] + d);
      ans.push_back(a[0] - d);
    } else {
      long long d = (a[1] - a[0]) / 2;
      cerr << "d=" << d << "\n";
      ans.push_back(a[1] + 2 * d);
      ans.push_back(a[0] - 2 * d);
      ans.push_back(a[0] + d);
    }
    print(ans);
    return 0;
  }
  unordered_map<long long, long long> map;
  for (int i = 1; i < a.size(); i++) {
    map[a[i] - a[i - 1]]++;
  }
  if (map.size() == 1) {
    long long d = map.begin()->first;
    if (d == 0)
      a.push_back(a[0]);
    else {
      ans.push_back(a[a.size() - 1] + d);
      ans.push_back(a[0] - d);
    }
    print(ans);
  } else if (map.size() == 2) {
    auto it2 = map.begin();
    auto it1 = it2++;
    if (it1->second == 1 && it1->first == 2 * it2->first) {
      for (int i = 1; i < a.size(); ++i) {
        if (a[i] - a[i - 1] == it1->first) ans.push_back(a[i - 1] + it2->first);
      }
      print(ans);
    } else if (it2->second == 1 && it2->first == 2 * it1->first) {
      for (int i = 1; i < a.size(); ++i) {
        if (a[i] - a[i - 1] == it2->first) ans.push_back(a[i - 1] + it1->first);
      }
      print(ans);
    } else
      cout << 0 << "\n";
  } else
    cout << 0 << "\n";
  cerr << "......^_^....."
       << "\n";
  return 0;
}
