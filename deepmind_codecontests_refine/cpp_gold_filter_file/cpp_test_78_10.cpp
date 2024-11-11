#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &num) {
  char c = getchar();
  T f = 1;
  num = 0;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    num = (num << 3) + (num << 1) + (c ^ 48);
    c = getchar();
  }
  num *= f;
}
template <typename T>
void qwq(T x) {
  if (x > 9) qwq(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void write(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  }
  qwq(x);
  putchar('\n');
}
template <typename T>
void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
int cnt[40];
vector<int> v;
int gcd(int n, int m) { return (!m) ? n : gcd(m, n % m); }
int main() {
  int t;
  read(t);
  while (t--) {
    v.clear();
    memset(cnt, 0, sizeof(cnt));
    int n;
    read(n);
    for (int i = 1; i <= n; i++) {
      int x;
      read(x);
      for (int j = 29; j >= 0; j--) cnt[j] += ((x & (1 << j)) != 0);
    }
    int s = cnt[0];
    for (int i = 1; i <= 29; i++) s = gcd(s, cnt[i]);
    if (s == 0) {
      for (int i = 1; i <= n; i++) {
        qwq(i);
        putchar((i == n) ? '\n' : ' ');
      }
    } else {
      for (int i = 1; i * i <= s; i++) {
        if (s % i != 0) continue;
        v.push_back(i);
        if (i * i != s) v.push_back(s / i);
      }
      sort(v.begin(), v.end());
      for (int i = 0; i <= (int)v.size() - 1; i++) {
        qwq(v[i]);
        putchar((i == (int)v.size() - 1) ? '\n' : ' ');
      }
    }
  }
  return 0;
}
