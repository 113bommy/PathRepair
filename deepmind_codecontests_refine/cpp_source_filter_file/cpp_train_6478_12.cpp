#include <bits/stdc++.h>
std::mt19937 rgn(std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
namespace io {
template <typename T>
inline void read(T& a) {
  int c = getchar(), sign = 0;
  a = 0;
  while (c < '0' || c > '9') sign += (c == '-'), c = getchar();
  while (c >= '0' && c <= '9') a = (a << 1) + (a << 3) + c - 48, c = getchar();
  if (sign & 1) a = -a;
}
template <typename T, typename... _T>
inline void read(T& a, _T&... argc) {
  read(a);
  read(argc...);
}
template <typename T>
inline void Write(T a) {
  if (a > 9) Write(a / 10);
  putchar(a % 10 + '0');
}
template <typename T>
inline void write(T a, char ch = ' ') {
  if (a < 0) putchar('-'), a = -a;
  Write(a);
  putchar(ch);
}
template <typename T>
inline void Min(T& a, T b) {
  a = min(a, b);
}
template <typename T>
inline void Max(T& a, T b) {
  a = max(a, b);
}
template <typename T, typename... _T>
inline void Min(T& a, T b, _T... c) {
  Min(a, b);
  Min(a, c...);
}
template <typename T, typename... _T>
inline void Max(T& a, T b, _T... c) {
  Max(a, b);
  Max(a, c...);
}
}  // namespace io
using namespace io;
const int maxn = 1e6 + 3;
const int N = 4e5 + 3;
const int mod = 1e9 + 7;
int n, m, q;
int dem[N], id[N], chot[N], a[N], b[N];
int k, h;
long long t[N + 3];
int dp[N];
string s;
bool kt[N];
map<int, vector<int>> maps;
vector<int> edge[N];
map<int, int>::iterator it;
template <typename T>
void answer(T x) {
  cout << x;
  exit(0);
}
void putstring(string x, char ch = ' ') {
  for (char c : x) putchar(c);
  putchar(ch);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int need = 0;
  int can = 0;
  for (int j = 1; j <= n; ++j) {
    cin >> b[j];
    if (b[j] && !a[j]) ++need;
    if (!b[j] && a[j]) ++can;
  }
  if (!need || !can)
    cout << "-1\n";
  else
    cout << (need + can) / can;
}
