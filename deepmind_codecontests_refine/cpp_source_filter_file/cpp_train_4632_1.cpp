#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <class T>
void chmax(T& l, const T r) {
  l = max(l, r);
}
template <class T>
void chmin(T& l, const T r) {
  l = min(l, r);
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
int a[1000];
int main() {
  int n, k, p, x, y;
  cin >> n >> k >> p >> x >> y;
  for (int i = 0; i < (k); i++) cin >> a[i];
  for (int i = 0; i < (n - k + 1); i++) {
    int j = n - k - i;
    vector<int> b(a, a + k);
    for (int _ = 0; _ < (i); _++) b.push_back(1);
    for (int _ = 0; _ < (j); _++) b.push_back(y);
    int sm = accumulate(b.begin(), b.end(), 0);
    sort(b.begin(), b.end());
    if (sm <= x && b[n / 2] == y) {
      for (int _ = 0; _ < (i); _++) printf("%d ", 1);
      for (int _ = 0; _ < (j); _++) printf("%d ", y);
      puts("");
      return 0;
    }
  }
  puts("-1");
  return 0;
}
