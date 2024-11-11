#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int N = 2000010;
const int M = 2000010;
const int P = 1000000007;
const int Inf = 1000000007;
const int Fni = -1000000007;
inline int qr() {
  int r = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    r = (r << 1) + (r << 3) + c - '0', c = getchar();
  }
  return r * f;
}
template <typename T>
void debug(T *const tp, int minn, int maxn, char v = ' ', char c = '\n') {
  for (int i = minn; i <= maxn; ++i) cout << tp[i] << v;
  cout << c;
}
int cnt;
int head[N];
struct Edge {
  int to;
  int val;
  int next;
} E[N * 2];
inline void add_e(int x, int y, int w = 0) {
  E[++cnt].to = y;
  E[cnt].val = w;
  E[cnt].next = head[x];
  head[x] = cnt;
}
template <typename T>
inline void add(T &x, T y, T mod) {
  x += y;
  x = x > mod ? x - mod : x;
}
template <typename T>
inline void dec(T &x, T y, T mod) {
  x -= y;
  x = x < 0 ? x + mod : x;
}
template <typename T>
inline T addn(T x, T y, T mod) {
  x += y;
  return (x = x > mod ? x - mod : x);
}
template <typename T>
inline T decn(T x, T y, T mod) {
  x -= y;
  return (x = x < 0 ? x + mod : x);
}
stack<int> s;
int n, q;
int L[N];
int R[N];
long long base[N];
long long ans1[N];
long long ans2[N];
inline void add1(int x, long long v) { ans1[x] += v; }
inline void add2(int x, long long v) { ans2[x] += v; }
int main() {
  cin >> n;
  int m;
  for (int i = 1; i <= n; ++i) base[i] = qr();
  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && base[s.top()] > base[i]) s.pop();
    L[i] = s.empty() ? 0 : s.top();
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && base[s.top()] >= base[i]) s.pop();
    R[i] = s.empty() ? n + 1 : s.top();
    s.push(i);
  }
  for (int i = 1; i <= n; ++i) {
    long long l = i - L[i];
    long long r = R[i] - i;
    long long t = l + r;
    long long L = l + 1;
    long long R = r + 1;
    if (l > r) {
      swap(l, r);
      swap(L, R);
    }
    add1(L, l * base[i]);
    add1(R, -l * base[i]);
    add1(r + 1, t * base[i]);
    add1(l + r, -t * base[i]);
    add2(1, base[i]);
    add2(L, -base[i] * L);
    add2(L + 1, base[i] * l);
    add2(R, -R * base[i]);
    add2(R + 1, r * base[i]);
    add2(t, base[i] * t);
    add2(t + 1, -base[i] * (t - 1));
  }
  for (int i = 1; i <= n; ++i) ans2[i] += ans2[i - 1];
  for (int i = 1; i <= n; ++i) ans2[i] += ans2[i - 1];
  for (int i = 1; i <= n; ++i) ans1[i] += ans1[i - 1];
  for (int i = 1; i <= n; ++i) ans1[i] += ans2[i];
  cin >> q;
  while (q--)
    m = qr(), printf("%.10lf\n", (double)ans1[m] / (double)(n - m + 1));
  return 0;
}
