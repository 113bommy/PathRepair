#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const int inf = mod;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
map<pair<int, int>, int> bit;
const int maxn = 100010;
void add(int value, int t, int w) {
  for (int i = t; i < maxn; i += (i & (-i))) {
    bit[make_pair(value, i)] += w;
  }
}
void query(int value, int t) {
  int ans = 0;
  for (int i = t; i > 0; i -= (i & (-i))) {
    ans += bit[make_pair(value, i)];
  }
  printf("%d\n", ans);
}
int main() {
  int n;
  (read(n));
  while (n--) {
    int type, tim, value;
    (read(type));
    (read(tim));
    (read(value));
    if (type == 1) {
      add(value, tim, 1);
    } else if (type == 2) {
      add(value, tim, -1);
    } else {
      query(value, tim);
    }
  }
  return 0;
}
