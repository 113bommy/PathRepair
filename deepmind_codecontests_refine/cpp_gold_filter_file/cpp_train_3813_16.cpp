#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
int n, m, k, a[103][103];
struct comp {
  bool operator()(pair<int, int> const &p1, pair<int, int> const &p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, comp> all[102];
int main() {
  int test, cases = 1;
  cin >> n >> m >> k;
  for (int i = (1); i < (n + 1); i++) {
    for (int j = (1); j < (m + 1); j++) cin >> a[i][j];
  }
  int ans1 = 0, ans2 = 0;
  for (int i = (1); i < (m + 1); i++) {
    int cnt = 0;
    for (int j = (1); j < (n + 1); j++) {
      int t = 0;
      if (a[j][i]) {
        int c = 0;
        for (int l = j; l <= n; l++) {
          if (a[l][i]) t++;
          c++;
          if (c == k) break;
        }
        all[i].push({t, cnt});
        cnt++;
      }
    }
    if (!all[i].empty()) {
      ans1 += all[i].top().first;
      ans2 += all[i].top().second;
    }
  }
  cout << ans1 << " " << ans2 << "\n";
  return 0;
}
