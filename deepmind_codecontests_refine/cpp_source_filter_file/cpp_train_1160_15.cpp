#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
namespace Bigcat {
template <typename T>
inline void max_s(T& a, const T& b) {
  a = max(a, b);
}
template <typename T>
inline void min_s(T& a, const T& b) {
  a = min(a, b);
}
template <typename T>
void sort_v(T& x) {
  sort(x.begin(), x.end());
}
template <typename T>
void erase_dup(T& x) {
  x.erase(unique(x.begin(), x.end()), x.end());
}
template <typename T, typename V>
int pos_l(const T& x, const V& v) {
  return lower_bound(x.begin(), x.end(), v) - x.begin();
}
template <typename T, typename V>
int pos_u(const T& x, const V& v) {
  return upper_bound(x.begin(), x.end(), v) - x.begin();
}
inline unsigned rand_g() {
  static mt19937 mt_rand((int)time(0));
  return mt_rand();
}
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using PII = pair<int, int>;
using VPII = vector<PII>;
}  // namespace Bigcat
using namespace Bigcat;
const LL base = LL(1e9 + 7);
const LL INFL = 1LL << 62;
const int INF = 1 << 30;
const int MAX = int(2e5 + 100);
struct Node {
  int x, y, w;
};
bool operator<(const Node& n0, const Node& n1) { return n0.x < n1.y; }
void solve1() {
  LL result = 0;
  int n;
  cin >> n;
  VI za(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> za[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    LL a = za[i], b = za[i + 1];
    if (a > b) swap(a, b);
    result += a * (b - a) + (b - a) * (n - b + 1);
  }
  result += za[0] * (n - za[0] + 1);
  result += za[n - 1] * (n - za[n - 1] + 1);
  cout << result / 2 << endl;
}
void io_init(char* s0) {
  string path(s0);
  int a = path.find("build\\");
  int b = path.find("Debug\\");
  if (a > 0 && b > a) {
    path = path.substr(0, a) + path.substr(a + 6, b - a - 6);
  } else
    path = "";
  const int inId = 1;
  const int outId = 0;
  if (inId > 0) {
    cerr << "redirect stdin to input " << inId << endl;
    string s = "input";
    s += to_string(inId);
    s += ".txt";
    if (path != "") s = path + s;
    auto r = freopen(s.c_str(), "r", stdin);
    if (r == nullptr) {
      cerr << "invalid input file " << s << endl;
      ;
      r = freopen("CON", "r", stdin);
    }
  }
  if (outId > 0) {
    cerr << "redirect stdout to stdout " << outId << endl;
    string s = "stdout";
    s += to_string(outId);
    s += ".txt";
    if (path != "") s = path + s;
    auto r = freopen(s.c_str(), "w", stdout);
    if (r == nullptr) {
      cerr << "invalid output file " << s << endl;
      ;
      r = freopen("CON", "w", stdout);
    }
  }
}
void solve() {
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve1();
  }
  int x = 1;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(11);
  solve();
}
