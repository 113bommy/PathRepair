#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <typename T, typename K>
inline void umax(T &a, K b) {
  a = max(a, (T)b);
}
template <typename T, typename K>
inline void umin(T &a, K b) {
  a = min(a, (T)b);
}
const int32_t N = 1510;
const long long INF = 1e16 + 10;
const long double EPS = 1e-6;
const long long II = 1e9;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<long long> cnt(5);
  for (int32_t i = 0; i < (5); i++) cin >> cnt[i];
  vector<string> ke = {"S", "M", "L", "XL", "XXL"};
  long long n;
  cin >> n;
  while (n--) {
    string second;
    cin >> second;
    long long idx = 0;
    while (ke[idx] != second) idx++;
    for (int32_t dst = 0; dst < (4); dst++) {
      if (idx + dst < 5 && cnt[idx + dst]) {
        idx += dst;
        break;
      }
      if (idx - dst >= 0 && cnt[idx - dst]) {
        idx -= dst;
        break;
      }
    }
    cout << ke[idx] << '\n';
    cnt[idx]--;
  }
}
