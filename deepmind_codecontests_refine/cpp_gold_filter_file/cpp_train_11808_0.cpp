#include <bits/stdc++.h>
using namespace std;
template <typename A>
string to_string(A* ptr) {
  stringstream ss;
  ss << "0x" << std::setw(16) << std::setfill('0') << std::hex
     << (uint64_t)(uintptr_t)ptr;
  return ss.str();
}
string to_string(char c) { return ((string) "'" + c) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int MX = 3009;
int n, K;
int p[MX];
bool visited[MX][MX];
int cnt100_suff[MX];
int cnt000_suff[MX];
void try_go(int i_new, int j_new, int k_new, queue<tuple<int, int, int> >& Q) {
  if (!visited[i_new][j_new]) {
    visited[i_new][j_new] = true;
    Q.push({i_new, j_new, k_new});
  }
}
int solve() {
  int result = 0;
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < n + 2; j++) visited[i][j] = false;
  }
  for (int i = n - 1; i >= 0; i--) {
    cnt100_suff[i] = p[i] == 100;
    cnt000_suff[i] = p[i] == 000;
    if (i + 1 < n) {
      cnt100_suff[i] += cnt100_suff[i + 1];
      cnt000_suff[i] += cnt000_suff[i + 1];
    }
  }
  queue<tuple<int, int, int> > Q;
  Q.push({0, 1, K});
  visited[0][1] = true;
  while (!Q.empty()) {
    auto [i, j, k] = Q.front();
    Q.pop();
    result++;
    if (i >= n) {
      assert(j == n + 1);
      continue;
    }
    if (j >= n) {
      continue;
    }
    if (k <= 0) continue;
    assert(0 <= i && i < j && j < n);
    assert(k > 0);
    int pi = p[i];
    bool pi_can_kill = pi > 0;
    bool pi_can_notkill = pi < 100;
    int cntj = (n - j);
    int c100 = cnt100_suff[j];
    int c000 = cnt000_suff[j];
    bool pj_can_kill = c000 < cntj;
    bool pj_can_notkill = c100 == 0;
    int k_new = k - 1;
    if (pi_can_kill && pj_can_kill) {
      try_go(j + 1, j + 2, k_new, Q);
    }
    if (pi_can_kill && pj_can_notkill) {
      try_go(i, j + 1, k_new, Q);
    }
    if (pi_can_notkill && pj_can_kill) {
      try_go(j, j + 1, k_new, Q);
    }
    if (pi_can_notkill && pj_can_notkill) {
      try_go(i, j, k_new, Q);
    }
  }
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TTT = 1;
  for (int ttt = 0; ttt < TTT; ttt++) {
    cin >> n >> K;
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << solve() << '\n';
  }
  return 0;
}
