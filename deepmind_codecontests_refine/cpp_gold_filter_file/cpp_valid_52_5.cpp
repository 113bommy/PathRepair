#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001;
void ap_99() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void solve() {
  int n;
  cin >> n;
  vector<int> v;
  long double sum = 0;
  for (int i = 0; i < (n); i++) {
    int t;
    cin >> t;
    sum += t;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  long double avg = 0;
  long double sum1 = 0;
  long double sum2 = 0;
  long double mx = -2000000001;
  for (int i = 0; i < (n - 1); i++) {
    sum1 += v[i];
    sum2 = sum - sum1;
    avg = sum1 / (i + 1) + sum2 / (n - i - 1);
    if (avg > mx) {
      mx = avg;
    }
  }
  cout << fixed << setprecision(12) << mx;
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
