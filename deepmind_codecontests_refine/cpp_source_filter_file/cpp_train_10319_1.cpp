#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
void Error(string s) {
  cout << s << '\n';
  exit(0);
}
void Fan_chipu();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  Fan_chipu();
}
const int maxn = 2e5 + 8;
long long a[maxn];
void Fan_chipu() {
  int n;
  long long t;
  cin >> n >> t;
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i];
  long long sum = 1e18 + 1, cnt = 0, ans = 0;
  do {
    ans += (long long)(t / sum) * cnt;
    t %= sum;
    sum = 0LL, cnt = 0;
    for (int i = 1; i <= (int)(n); ++i) {
      if (sum + a[i] <= t) ++cnt, sum += a[i];
    }
  } while (sum);
  cout << ans;
}
