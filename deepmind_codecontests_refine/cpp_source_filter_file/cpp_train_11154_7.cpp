#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
template <class T>
inline void umin(T &x, T y) {
  x = x < y ? x : y;
}
template <class T>
inline void umax(T &x, T y) {
  x = x > y ? x : y;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const int N = 303000;
int l, r, m;
pair<long long, long long> sta[N];
int top;
long long k, b;
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return pair<long long, long long>(a.first - b.first, a.second - b.second);
}
double Cross(pair<long long, long long> a, pair<long long, long long> b) {
  return 1.0 * a.first * b.second - 1.0 * a.second * b.first;
}
long long calc(pair<long long, long long> a) {
  return 1LL * k * a.first + a.second + b;
}
int main() {
  l = 1;
  read(r);
  read(m);
  sta[++top] = pair<long long, long long>(1, 0);
  while (m--) {
    int op;
    read(op);
    if (op == 1) {
      int x;
      read(x);
      l -= x;
      k = b = 0;
      top = 1;
      sta[top] = pair<long long, long long>(l, 0);
    } else if (op == 2) {
      int x;
      read(x);
      pair<long long, long long> c =
          pair<long long, long long>(r + 1, -1LL * k * (r + 1) - b);
      while (top > 1 && Cross(sta[top] - sta[top - 1], c - sta[top]) <= 0)
        top--;
      sta[++top] = c;
      r += x;
    } else {
      int B, s;
      read(B);
      read(s);
      k += s;
      b += B - 1LL * l * s;
    }
    while (top > 1 && calc(sta[top]) >= calc(sta[top - 1])) top--;
    printf("%d %lld\n", sta[top].first - l + 1, calc(sta[top]));
  }
  return 0;
}
