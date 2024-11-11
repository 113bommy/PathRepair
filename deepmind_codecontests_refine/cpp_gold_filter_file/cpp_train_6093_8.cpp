#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &x) {
  s << "[";
  for (auto it : x) {
    s << "it"
      << ", ";
  }
  s << "]";
  return s;
}
template <typename T>
ostream &operator<<(ostream &s, const set<T> &x) {
  s << "{";
  for (auto it : x) {
    s << "it"
      << ", ";
  }
  s << "}";
  return s;
}
const int maxn = 200103;
long long a[maxn], c[maxn];
int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i <= n; i++) cin >> a[i];
  long long cur = 0;
  for (int i = 0; i <= n || cur != 0; i++) {
    cur += a[i];
    c[i] = cur % 2;
    cur /= 2;
  }
  for (int i = maxn - 1; i >= 1; i--) {
    if (c[i] * c[i - 1] == -1) c[i - 1] = c[i], c[i] = 0;
  }
  int mini = -1, maxi = -1;
  for (int i = 0; i < maxn; i++) {
    if (c[i] != 0) {
      if (mini == -1 || mini > i) mini = i;
      if (maxi == -1 || maxi < i) maxi = i;
    }
  }
  int ans = 0;
  if (maxi - mini <= 35) {
    long long x = 0;
    for (int i = maxi; i >= mini; i--) x = x * 2 + c[i];
    for (int i = mini; i >= 0 && abs(x) < 1e12; i--) {
      long long nv = a[i] - x;
      if (abs(nv) <= k && i <= n) {
        if (!(i == n && nv == 0)) ans++;
      }
      x *= 2;
    }
  }
  cout << ans << "\n";
  return 0;
}
