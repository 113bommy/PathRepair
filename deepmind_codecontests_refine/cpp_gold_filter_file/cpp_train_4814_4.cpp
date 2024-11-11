#include <bits/stdc++.h>
template <typename T>
bool chmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool chmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline int lcm(int a, int b) { return a * b / gcd(a, b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = int(0); i < int(n); ++i) cin >> a[i];
    sort(a, a + n);
    long long sum = 0, avg = 0.0;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i];
      avg = sum / (double(n - i));
      if (avg >= x)
        ++ans;
      else
        break;
    }
    if (ans == 0) {
      cout << 0 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
