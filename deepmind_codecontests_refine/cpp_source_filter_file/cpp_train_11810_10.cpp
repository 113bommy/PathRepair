#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-8;
const double PI = acos(-1);
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &o, const vector<T> &t) {
  o << '[';
  for (__typeof((t).begin()) i = (t).begin(); i != (t).end(); ++i) {
    if (i != t.begin()) o << ',';
    o << *i;
  }
  return o << ']';
}
template <class S, class T>
ostream &operator<<(ostream &o, const pair<S, T> &t) {
  return o << '(' << t.first << ',' << t.second << ')';
}
template <int N, class Tp>
void out(ostream &, const Tp &) {}
template <int N, class Tp, class, class... Ts>
void out(ostream &o, const Tp &t) {
  if (N) o << ',';
  o << get<N>(t);
  out<N + 1, Tp, Ts...>(o, t);
}
template <class... Ts>
ostream &operator<<(ostream &o, const tuple<Ts...> &t) {
  o << '(';
  out<0, tuple<Ts...>, Ts...>(o, t);
  return o << ')';
}
template <class T>
void output(T *a, int n) {
  for (int i = 0; i < (int)(n); ++i) {
    if (i) cout << ',';
    cout << a[i];
  }
  cout << endl;
}
template <class T>
void output(T *a, int n, int m) {
  for (int i = 0; i < (int)(n); ++i) output(a[i], m);
}
template <class T>
void output(T t) {
  if (t < 0) t = -t, putchar('-');
  static int c[20];
  int k = 0;
  while (t) c[k++] = t % 10, t /= 10;
  if (!k) c[k++] = 0;
  while (k) putchar(c[--k] ^ 48);
}
template <class S, class... T>
void output(S a, T... t) {
  output(a);
  putchar(' ');
  output(t...);
}
template <class T>
bool input(T &t) {
  t = 0;
  int n = 0, c;
  while (~(c = getchar()) && !isdigit(c) && c != '-')
    ;
  if (!~c) return 0;
  if (c == '-')
    n = 1;
  else
    t = c ^ 48;
  while (isdigit(c = getchar())) t = 10 * t + c - '0';
  t = n ? -t : t;
  return 1;
}
template <class S, class... T>
bool input(S &a, T &...t) {
  input(a);
  return input(t...);
}
int a[2000];
int dp[2000][1 << 11];
const int mod = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a > mod) a -= mod;
}
int ts[(1 << 11) + 1][2];
int main() {
  int n, k;
  while (input(n, k)) {
    k--;
    for (int i = 0; i < (int)(n); ++i) input(a[i]);
    for (int S = 0; S < (int)(1 << k); ++S) {
      if (!S) {
        ts[S][0] = 1 << 0;
        ts[S][1] = 1 << 1;
      } else {
        int z = __builtin_ctz(S);
        if (z > 0) {
          ts[S][0] = S | 1 << 0;
        } else {
          ts[S][0] = S + 1;
        }
        if (z > 1) {
          ts[S][1] = S | 1 << 1;
        } else if (z == 0) {
          ts[S][1] = 1 << 1;
        } else {
          ts[S][1] = S + 2;
        }
      }
    }
    ts[1 << k][0] = ts[1 << k][1] = 1 << k;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < (int)(n); ++i)
      for (int S = 0; S < (int)((1 << k) + 1); ++S)
        if (dp[i][S]) {
          if (a[i] == 0 || a[i] == 2) {
            add(dp[i + 1][ts[S][0]], dp[i][S]);
          }
          if (a[i] == 0 || a[i] == 4) {
            add(dp[i + 1][ts[S][1]], dp[i][S]);
          }
        }
    output(dp[n][1 << k]);
    puts("");
  }
}
