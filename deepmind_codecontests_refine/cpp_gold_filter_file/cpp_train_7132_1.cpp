#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
const long long inf = 1e18;
inline long long max(long long a, int32_t b) { return a > b ? a : b; }
inline long long max(int32_t a, long long b) { return a > b ? a : b; }
inline long long min(long long a, int32_t b) { return a < b ? a : b; }
inline long long min(int32_t a, long long b) { return a < b ? a : b; }
long long d4_1[4] = {1, 0, -1, 0};
long long d4_2[4] = {0, 1, 0, -1};
long long d8_1[8] = {1, 1, 1, -1, -1, -1, 0, 0};
long long d8_2[8] = {0, -1, 1, 0, -1, 1, 1, -1};
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return to_string(string(1, c)); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (long long i = 0; i < static_cast<long long>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug() { cout << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {}
void solve() {
  string s;
  cin >> s;
  stack<char> Stack;
  long long ans = 0;
  for (long long i = 0; s[i]; i++) {
    if (s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '(') {
      Stack.push(s[i]);
    } else {
      if (Stack.empty()) {
        cout << "Impossible\n";
        return;
      }
      if (s[i] == '}') {
        if (Stack.top() != '{') {
          ans++;
        }
      } else if (s[i] == ']') {
        if (Stack.top() != '[') {
          ans++;
        }
      } else if (s[i] == '>') {
        if (Stack.top() != '<') {
          ans++;
        }
      } else {
        if (Stack.top() != '(') {
          ans++;
        }
      }
      Stack.pop();
    }
  }
  if (!Stack.empty()) {
    cout << "Impossible\n";
    return;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
