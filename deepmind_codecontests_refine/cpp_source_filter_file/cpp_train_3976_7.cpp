#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
void clock_out() {
  cerr << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
}
void fileio() {
  freopen("/home/dwai/Desktop/cp/input.txt", "r", stdin);
  freopen("/home/dwai/Desktop/cp/output.txt", "w", stdout);
  freopen("/home/dwai/Desktop/cp/debug.txt", "w", stderr);
}
void ofileio() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
int IT_MAX = 1 << 20;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
bool sc(long long str, long long in, long long x, long long y) {
  return (str + x > in + y);
}
void solve() {
  long long str, in, exp;
  cin >> str >> in >> exp;
  if (str < in) {
    if (exp + str <= in) {
      cout << 0 << "\n";
      return;
    }
    long long x = in - str + 1;
    exp -= x;
    str += x;
  }
  long long l = 0, r = exp;
  long long c = 0;
  while (l < r) {
    c++;
    if (c >= 100) break;
    long long mid = (l + r) >> 1;
    if (sc(str, in, mid, exp - mid)) {
      r = mid;
    } else
      l = mid + 1;
  }
  str += r;
  long long uin = exp - r + in;
  cout << uin - in + 1 << "\n";
}
int main() {
  42;
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
