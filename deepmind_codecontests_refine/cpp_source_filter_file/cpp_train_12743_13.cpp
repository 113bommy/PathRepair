#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
double pi = 3.141592653589793238;
const int M = 1e9 + 7;
const int Nmax = 5005;
const int MM = 998244353;
const int N = 100005;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  while (T--) {
    long long int n, cnt = 0;
    cin >> n;
    vector<long long int> v;
    for (int i = 0; i < 2 * n; i++) {
      long long int a, b;
      char c;
      cin >> a >> c >> b;
      v.push_back(b);
      if (b == 0) cnt++;
    }
    long long int sum = accumulate(v.begin(), v.end(), 0);
    long long int ans = abs(1000 * n - sum);
    long long int sol = ans;
    for (int i = 0; i <= min(cnt, n); i++) {
      sol = min(sol, abs(ans - i * 1000));
    }
    double anss = sol;
    anss /= 1000;
    cout << fixed << setprecision(3) << anss << "\n";
  }
  return 0;
}
