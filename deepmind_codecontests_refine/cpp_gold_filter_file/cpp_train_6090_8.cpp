#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  long long first = 0;
  char ch = getchar();
  bool positive = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') positive = 0;
  for (; isdigit(ch); ch = getchar()) first = first * 10 + ch - '0';
  return positive ? first : -first;
}
inline void write(long long a) {
  if (a < 0) {
    a = -a;
    putchar('-');
  }
  if (a >= 10) write(a / 10);
  putchar('0' + a % 10);
}
inline void writeln(long long a) {
  write(a);
  puts("");
}
inline void wri(long long a) {
  write(a);
  putchar(' ');
}
const int N = 100005, IN = 1e5;
pair<long long, long long> q[N << 3], Q[N << 3];
int top, tt;
long long cha(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first * b.second - a.second * b.first;
}
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
long double solve(pair<long long, long long> a, pair<long long, long long> b,
                  pair<long long, long long> c) {
  long double A = 2 * (a.first - b.first), B = 2 * (a.second - b.second),
              C = a.first * a.first + a.second * a.second - b.first * b.first -
                  b.second * b.second;
  long double D = 2 * (a.first - c.first), E = 2 * (a.second - c.second),
              F = a.first * a.first + a.second * a.second - c.first * c.first -
                  c.second * c.second;
  long double Y = (C * D - F * A) / (B * D - E * A),
              X = a.first != b.first ? (C - B * Y) / A : (F - E * Y) / D;
  return sqrt((a.first - X) * (a.first - X) + (a.second - Y) * (a.second - Y));
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  long long t = cha(a - q[1], b - q[1]);
  return t == 0 ? abs(a.first - q[1].first) + abs(a.second - q[1].second) <
                      abs(b.first - q[1].first) + abs(b.second - q[1].second)
                : t > 0;
}
int main() {
  int n = read(), tt = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    int first = read(), second = read(), v = read();
    if (first + v <= IN) {
      q[++tt] = make_pair(first + v, second);
    } else {
      if (second - (first + v - IN) > 0)
        q[++tt] = make_pair(IN, second - (first + v - IN));
      else
        q[++tt] = make_pair(IN, 0);
      if (second + (first + v - IN) < IN)
        q[++tt] = make_pair(IN, second + (first + v - IN));
      else
        q[++tt] = make_pair(IN, IN);
    }
    if (first - v >= 0) {
      q[++tt] = make_pair(first - v, second);
    } else {
      if (second - (v - first) > 0)
        q[++tt] = make_pair(0, second - (v - first));
      else
        q[++tt] = make_pair(0, 0);
      if (second + (v - first) < IN)
        q[++tt] = make_pair(0, second + (v - first));
      else
        q[++tt] = make_pair(0, IN);
    }
    if (second + v <= IN) {
      q[++tt] = make_pair(first, second + v);
    } else {
      if (first - (second + v - IN) > 0)
        q[++tt] = make_pair(first - (second + v - IN), IN);
      if (first + (second + v - IN) < IN)
        q[++tt] = make_pair(first + (second + v - IN), IN);
    }
    if (second - v >= 0) {
      q[++tt] = make_pair(first, second - v);
    } else {
      if (first - (v - second) > 0)
        q[++tt] = make_pair(first - (v - second), 0);
      if (first + (v - second) < IN)
        q[++tt] = make_pair(first + (v - second), 0);
    }
  }
  for (int i = (int)(2); i <= (int)(tt); i++)
    if (q[i] < q[1]) swap(q[1], q[i]);
  sort(q + 2, q + tt + 1, cmp);
  Q[top = 0] = q[1];
  for (int i = (int)(2); i <= (int)(tt); i++) {
    while (top >= 1 && cha(Q[top] - Q[top - 1], q[i] - Q[top]) <= 0) top--;
    Q[++top] = q[i];
  }
  top++;
  long double mx = -1;
  int pos;
  for (int i = (int)(0); i <= (int)(top - 1); i++) {
    long double t = solve(Q[i], Q[(i + 1) % top], Q[(i + 2) % top]);
    if (t > mx) {
      mx = t;
      pos = i;
    }
  }
  for (int i = (int)(0); i <= (int)(2); i++)
    wri(Q[(pos + i) % top].first), writeln(Q[(pos + i) % top].second);
}
