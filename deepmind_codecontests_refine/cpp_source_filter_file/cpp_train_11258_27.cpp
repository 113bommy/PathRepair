#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const long long int MOD = 1e9 + 7, LIM = 1e5 + 5;
const long double EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long w;
  cin >> w;
  long long int cnt[9] = {0};
  for (int i = 1; i < 9; i++) cin >> cnt[i];
  long long total = 0;
  for (int i = 1; i < 9; i++) {
    total += (i)*cnt[i];
  }
  if (total <= w) {
    cout << total << endl;
    return 0;
  }
  long long int ogw = w;
  for (int i = 8; i >= 1; i--) {
    long long int x = min(cnt[i], (long long int)(w - 5000) / i);
    x = max(x, 0LL);
    w -= x * i;
    cnt[i] -= x;
  }
  int dp[5001] = {0};
  dp[0] = 1;
  for (int i = 1; i < 9; i++) {
    for (int j = 0; j < min(cnt[i], 5000LL); j++) {
      for (int k = 5000; k >= 0; k--) {
        if (dp[k] && k + i < 5001) {
          dp[k + i] = 1;
        }
      }
    }
  }
  int maxdif = 0;
  for (int j = w; j >= 0; j--) {
    if (dp[j]) {
      maxdif = j;
      break;
    }
  }
  cout << ogw - (w - maxdif) << endl;
  return 0;
}
