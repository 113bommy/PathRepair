#include <bits/stdc++.h>
using namespace std;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MAXN = 1000000;
const int INF = 0x3f3f3f3f;
long long cost[MAXN][11], step[MAXN][11];
template <class A>
A get(A x) {
  A mx = 0;
  while (x) {
    mx = max(mx, x % 10);
    x /= 10;
  }
  return mx;
}
int main() {
  long long N;
  scanf("%lld", &N);
  for (int v = 0; v < MAXN; ++v) {
    for (int d = 1; d < 10; ++d) {
      int m = max(get(v), d);
      if (v - m < 0) {
        step[v][d] = 1;
        cost[v][d] = m;
      } else {
        step[v][d] = step[v - m][d] + 1;
        cost[v][d] = cost[v - m][d] + m;
      }
    }
  }
  long long ans = 0;
  while (N >= MAXN) {
    int m = get(N / MAXN);
    ans += step[N / MAXN][m];
    N -= cost[N / MAXN][m];
  }
  while (N > 0) {
    int m = get(N);
    N -= m;
    ++ans;
  }
  printf("%lld\n", ans);
  return 0;
}
