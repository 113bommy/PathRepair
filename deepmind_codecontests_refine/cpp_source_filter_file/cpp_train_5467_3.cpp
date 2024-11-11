#include <bits/stdc++.h>
using namespace std;
template <typename...>
static inline int getchar_unlocked(void) {
  return getchar();
}
template <typename...>
static inline void putchar_unlocked(int c) {
  putchar(c);
}
void reader(int& x) {
  int k, m = 0;
  x = 0;
  for (;;) {
    (k) = getchar_unlocked();
    if (k == '-') {
      m = 1;
      break;
    }
    if ('0' <= k && k <= '9') {
      x = k - '0';
      break;
    }
  }
  for (;;) {
    (k) = getchar_unlocked();
    if (k < '0' || k > '9') break;
    x = x * 10 + k - '0';
  }
  if (m) x = -x;
}
void reader(long long& x) {
  int k, m = 0;
  x = 0;
  for (;;) {
    (k) = getchar_unlocked();
    if (k == '-') {
      m = 1;
      break;
    }
    if ('0' <= k && k <= '9') {
      x = k - '0';
      break;
    }
  }
  for (;;) {
    (k) = getchar_unlocked();
    if (k < '0' || k > '9') break;
    x = x * 10 + k - '0';
  }
  if (m) x = -x;
}
int reader(char c[]) {
  int i, s = 0;
  for (;;) {
    (i) = getchar_unlocked();
    if (i != ' ' && i != '\n' && i != '\r' && i != '\t' && i != EOF) break;
  }
  c[s++] = i;
  for (;;) {
    (i) = getchar_unlocked();
    if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break;
    c[s++] = i;
  }
  c[s] = '\0';
  return s;
}
template <class T, class S>
void reader(T& x, S& y) {
  reader(x);
  reader(y);
}
template <class T, class S, class U>
void reader(T& x, S& y, U& z) {
  reader(x);
  reader(y);
  reader(z);
}
template <class T, class S, class U, class V>
void reader(T& x, S& y, U& z, V& w) {
  reader(x);
  reader(y);
  reader(z);
  reader(w);
}
void writer(int x, char c) {
  int s = 0, m = 0;
  char f[10];
  if (x < 0) m = 1, x = -x;
  while (x) f[s++] = x % 10, x /= 10;
  if (!s) f[s++] = 0;
  if (m) putchar_unlocked('-');
  while (s--) putchar_unlocked(f[s] + '0');
  putchar_unlocked(c);
}
void writer(long long x, char c) {
  int s = 0, m = 0;
  char f[20];
  if (x < 0) m = 1, x = -x;
  while (x) f[s++] = x % 10, x /= 10;
  if (!s) f[s++] = 0;
  if (m) putchar_unlocked('-');
  while (s--) putchar_unlocked(f[s] + '0');
  putchar_unlocked(c);
}
void writer(const char c[]) {
  int i;
  for (i = 0; c[i] != '\0'; i++) putchar_unlocked(c[i]);
}
void writer(const char x[], char c) {
  int i;
  for (i = 0; x[i] != '\0'; i++) putchar_unlocked(x[i]);
  putchar_unlocked(c);
}
template <class T>
void writerLn(T x) {
  writer(x, '\n');
}
template <class T, class S>
void writerLn(T x, S y) {
  writer(x, ' ');
  writer(y, '\n');
}
template <class T, class S, class U>
void writerLn(T x, S y, U z) {
  writer(x, ' ');
  writer(y, ' ');
  writer(z, '\n');
}
template <class T>
void writerArr(T x[], int n) {
  if (!n) {
    putchar_unlocked('\n');
    return;
  }
  for (int i = 0; i < (n - 1); i++) writer(x[i], ' ');
  writer(x[n - 1], '\n');
}
template <class T>
void chmax(T& l, const T r) {
  l = max(l, r);
}
template <class T>
void chmin(T& l, const T r) {
  l = min(l, r);
}
int h, w;
struct P {
  int l, r, u, d;
  P() : l(0), r(w), u(0), d(h) {}
  char move(char c) {
    if (c == 'L')
      l++, r++;
    else if (c == 'R')
      l--, r--;
    else if (c == 'U')
      u++, d++;
    else if (c == 'D')
      u--, d--;
    char ret = 'N';
    if (l < 0) ret = 'L';
    if (r > w) ret = 'R';
    if (u < 0) ret = 'U';
    if (d > h) ret = 'D';
    l = max(0, min(l, w));
    r = max(0, min(r, w));
    u = max(0, min(u, h));
    d = max(0, min(d, h));
    return ret;
  }
  bool operator==(const P& x) {
    return tie(l, r, u, d) == tie(x.l, x.r, x.u, x.d);
  }
  bool is_end() const { return l == r || u == d; }
  void print() const { printf("[%d,%d) * [%d,%d)", l, r, u, d); }
};
const int MOD = ((int)1e9) + 7;
int main() {
  int n;
  reader(n, h, w);
  string s;
  cin >> s;
  P p;
  vector<pair<int, char>> evt;
  int time = 0;
  for (auto c : s) {
    time++;
    char x = p.move(c);
    if (c != 'N') {
      evt.emplace_back(time, x);
    }
  }
  time = 0;
  P move1 = p;
  vector<pair<int, char>> evt2;
  for (auto c : s) {
    time++;
    char x = p.move(c);
    if (c != 'N') {
      evt2.emplace_back(time, x);
    }
  }
  if (move1 == p && !move1.is_end()) {
    puts("-1");
    return 0;
  }
  int rw = w, rh = h;
  long long ans = 0;
  for (auto tc : evt) {
    if (rw == 0 || rh == 0) break;
    long long timing = tc.first, red;
    if (tc.second == 'L' || tc.second == 'R') {
      red = rh;
      rw--;
    } else {
      red = rw;
      rh--;
    }
    timing %= MOD;
    ans = (ans + timing * red) % MOD;
  }
  long long loop = 1;
  while (rw != 0 && rh != 0) {
    for (auto tc : evt2) {
      if (rw == 0 || rh == 0) break;
      long long timing = tc.first + loop * n, red;
      if (tc.second == 'L' || tc.second == 'R') {
        red = rh;
        rw--;
      } else {
        red = rw;
        rh--;
      }
      timing %= MOD;
      ans = (ans + timing * red) % MOD;
    }
    loop++;
  }
  ans = (ans % MOD + MOD) % MOD;
  writerLn(ans);
}
