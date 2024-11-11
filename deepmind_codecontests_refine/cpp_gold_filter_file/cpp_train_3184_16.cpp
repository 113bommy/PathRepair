#include <bits/stdc++.h>
using namespace std;
inline void read_string_to_vector(vector<string> &vec) {
  string str;
  getline(cin, str);
  vec.push_back(str);
}
template <typename T>
inline void read_digit_to_vector(vector<T> &vec) {
  T t;
  cin >> t;
  vec.push_back(t);
}
long long n, ts, te, t;
long long a[100001];
long long b[100001];
long long answ;
long long ma = 1e14;
int main() {
  answ = -1;
  ios::sync_with_stdio(false);
  scanf("%lld %lld %lld", &ts, &te, &t);
  scanf("%lld", &n);
  for (register long long i = 0; i < n; ++i) scanf("%lld", a + i);
  b[0] = max(ts, a[0]);
  for (register long long i = 1; i < n; ++i) b[i] = max(b[i - 1] + t, a[i]);
  if (ts < a[0] || a[0]) {
    answ = min(a[0] - 1, ts);
    ma = 0;
    if (answ < ts) ma = ts - answ;
  }
  for (register long long i = 1; i < n; ++i) {
    if (b[i] + t > te) break;
    if (b[i - 1] + t < a[i] && ma >= a[i] - 1) {
      answ = a[i] - 1;
      ma = a[i] - 1;
    }
  }
  for (register long long i = 1; i < n; ++i) {
    if (b[i] + t > te) break;
    if (ma >= b[i] - (a[i] - 1)) {
      answ = a[i] - 1;
      ma = b[i] - (a[i] - 1);
    }
  }
  if (b[n - 1] + t + t <= te) answ = b[n - 1] + t;
  if (!n) answ = b[0];
  printf("%lld", answ);
  return 0;
}
