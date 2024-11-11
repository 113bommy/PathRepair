#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, ans, m, p[N];
set<pair<int, int> > s;
bool check(int x) {
  for (auto p : s) {
    int u = (p.first + x) % n, v = (p.second + x) % n;
    if (u > v) swap(u, v);
    if (s.find(make_pair(u, v)) == s.end()) return 0;
  }
  return 1;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return x * f;
}
int main() {
  for (int i = 2; i < N; i++)
    if (!p[i])
      for (int j = 2; j * i < N; j++) p[i * j] = 1;
  n = read();
  m = read();
  while (m--) {
    int u = read() - 1, v = read() - 1;
    if (u > v) swap(u, v);
    s.insert(make_pair(u, v));
  }
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) {
      if (check(i)) {
        puts("Yes");
        return 0;
      } else if (i > 1 && check(n / i)) {
        puts("Yes");
        return 0;
      }
    }
  puts("No");
  return 0;
}
