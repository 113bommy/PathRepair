#include <bits/stdc++.h>
using namespace std;
bool desc_sort(const int& lhs, const int& rhs) { return lhs > rhs; }
bool desc_pii_sort(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  return lhs > rhs;
}
bool second_sort(const pair<int, int>& lhs, const pair<int, int>& rhs) {
  pair<int, int> a, b;
  a.first = lhs.second;
  a.second = lhs.first;
  b.first = rhs.second;
  b.second = rhs.first;
  return a < b;
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> second) {
  os << "{ ";
  for (auto s : second) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
inline long long fast_expo(long long base, long long power,
                           long long modulo = 1e0) {
  base %= modulo;
  if (base < 0LL) base += modulo;
  long long x = base, cnt = power, ans = 1LL;
  while (cnt) {
    if (cnt & 1LL) ans = (ans * x) % modulo;
    x = (x * x) % modulo;
    cnt >>= 1LL;
  }
  return ans;
}
inline long long inv(long long base, long long modulo = 1e0) {
  return fast_expo(base, modulo - 2LL, modulo);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < k) {
    cout << "-1\n";
    return 0;
  }
  sort(a, a + n, desc_sort);
  int start = 1;
  int end = 10000001;
  while (start < end) {
    int mid;
    mid = (start + end) / 2;
    vector<int> dp;
    dp.assign(10000001, 0);
    dp[0] = 0;
    if (mid <= 1) dp[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
      if (i < mid)
        dp[i] = 0;
      else if (i & 1) {
        dp[i] = max(1, dp[i / 2] + dp[i / 2 + 1]);
      } else {
        dp[i] = max(1, dp[i / 2] + dp[i / 2]);
      }
    }
    long long cc = 0;
    for (int i = 0; i < n; i++) {
      cc += dp[a[i]];
    }
    if (cc >= k) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  cout << start - 1 << "\n";
  return 0;
}
