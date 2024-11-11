#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000404;
const long long MOD = 1000000007ll;
const long double PI = acos(-1.0);
const long long INF = 1000000000000000404ll;
const long double EPS = 1e-9;
template <typename t1, typename t2>
inline void upmax(t1 &a, t2 b) {
  a = max(a, (t1)b);
}
template <typename t1, typename t2>
inline void upmin(t1 &a, t2 b) {
  a = min(a, (t1)b);
}
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
inline bool pal(string &x) {
  int n = (int)x.length();
  for (int i = 0; i < n / 2; i++) {
    if (x[i] != x[n - i - 1]) return 0;
  }
  return 1;
}
template <typename T>
inline void rev(T &x) {
  int n = (int((x.size())));
  for (int i = 0; i < n / 2; i++) swap(x[i], x[n - i - 1]);
}
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
class compare {
 public:
  bool operator()(const int a, const int b) const { return 1; }
};
int SQ = 400;
int x[111111], y[111111];
void solve() {
  string s;
  cin >> s;
  int n = (int((s.size())));
  bool bad = false;
  bool good = false;
  unordered_map<char, int> m;
  m['a'] = 1;
  m['e'] = 1;
  m['i'] = 1;
  m['o'] = 1;
  m['u'] = 1;
  for (int i = 2; i < n; i++) {
    if (m[s[i]] + m[s[i - 1]] + m[s[i - 2]] == 0 &&
        (s[i] != s[i - 1] || s[i - 2] != s[i])) {
      bad = true;
    }
  }
  int last = -1;
  if (bad == false)
    cout << s;
  else {
    for (int i = 0; i < min(2, n); i++) cout << s[i];
    for (int i = 2; i < n; i++) {
      if (i - last >= 2 && m[s[i]] + m[s[i - 1]] + m[s[i - 2]] == 0 &&
          (s[i] != s[i - 1] || s[i - 2] != s[i])) {
        last = i;
        cout << ' ';
      }
      cout << s[i];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  };
  getchar();
  getchar();
  return 0;
}
