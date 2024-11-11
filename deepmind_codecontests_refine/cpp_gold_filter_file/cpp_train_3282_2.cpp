#include <bits/stdc++.h>
using namespace std;
const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
  return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp++)
                  : *rp++;
}
inline int read_int() {
  int x = 0;
  char ch = read_char(), flag = 0;
  while (ch != '-' && (ch < '0' || ch > '9')) {
    ch = read_char();
  }
  if (ch == '-') {
    flag = 1;
    ch = read_char();
  }
  for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
    x = x * 10 + (ch - '0');
  }
  return flag ? -x : x;
}
const int MAX_N = 100000 + 5;
int N, T, V, x[MAX_N], s[MAX_N];
struct Event {
  int opt, tim, val, ans;
} e[MAX_N];
vector<int> ev[MAX_N];
int main() {
  N = read_int();
  for (int i = 1; i <= N; i++) {
    e[i].opt = read_int();
    e[i].tim = read_int();
    e[i].val = read_int();
    x[i] = e[i].val;
  }
  sort(x + 1, x + 1 + N);
  V = unique(x + 1, x + 1 + N) - x - 1;
  for (int i = 1; i <= N; i++) {
    e[i].val = lower_bound(x + 1, x + 1 + V, e[i].val) - x;
    ev[e[i].val].push_back(i);
  }
  for (int v = 1; v <= V; v++) {
    T = 0;
    for (int i : ev[v]) {
      x[++T] = e[i].tim;
    }
    sort(x + 1, x + 1 + T);
    T = unique(x + 1, x + 1 + T) - x - 1;
    for (int i : ev[v]) {
      e[i].tim = lower_bound(x + 1, x + 1 + T, e[i].tim) - x;
      if (e[i].opt == 1) {
        for (int j = e[i].tim; j <= T; j += j & -j) {
          s[j]++;
        }
      } else if (e[i].opt == 2) {
        for (int j = e[i].tim; j <= T; j += j & -j) {
          s[j]--;
        }
      } else {
        for (int j = e[i].tim; j >= 1; j -= j & -j) {
          e[i].ans += s[j];
        }
      }
    }
    for (int i : ev[v]) {
      if (e[i].opt <= 2) {
        for (int j = e[i].tim; j <= T; j += j & -j) {
          s[j] = 0;
        }
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    if (e[i].opt == 3) {
      printf("%d\n", e[i].ans);
    }
  }
  return 0;
}
