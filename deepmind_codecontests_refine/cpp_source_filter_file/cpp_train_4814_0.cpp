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
    reverse(a, a + n);
    vector<long long> pre;
    for (int i = int(0); i < int(n); ++i) {
      pre.push_back(1LL * ((pre.size() ? pre.back() : 0) + 1LL * a[i]));
    }
    reverse(pre.begin(), pre.end());
    int ans = -1;
    for (int i = int(0); i < int(n); ++i) {
      if (float(pre[i]) / (n - i) >= x) {
        ans = n - i;
        break;
      }
    }
    if (ans == -1) {
      cout << 0 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
