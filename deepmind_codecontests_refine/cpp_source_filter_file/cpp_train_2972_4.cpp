#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
pair<long long, long long> P[maxn];
long long cross(pair<long long, long long> a, pair<long long, long long> b,
                pair<long long, long long> c) {
  return abs((b.first - a.first) * (c.second - a.second) -
             (b.second - a.second) * (c.first - a.first));
}
int main() {
  int n = read(), s = read();
  for (int i = 1; i <= n; i++) scanf("%I64dI64d", &P[i].first, &P[i].second);
  pair<long long, long long> a = P[0], b = P[1], c = P[2];
  long long ans = cross(a, b, c);
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int i = 1; i <= n; i++) {
      long long tmp = cross(P[i], b, c);
      if (tmp > ans) {
        ans = tmp;
        a = P[i];
        flag = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      long long tmp = cross(a, P[i], c);
      if (tmp > ans) {
        ans = tmp;
        b = P[i];
        flag = 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      long long tmp = cross(a, b, P[i]);
      if (tmp > ans) {
        ans = tmp;
        c = P[i];
        flag = 1;
      }
    }
  }
  cout << a.first + b.first - c.first << " " << a.second + b.second - c.second
       << "\n";
  cout << a.first - b.first + c.first << " " << a.second - b.second + c.second
       << "\n";
  cout << b.first + c.first - a.first << " " << b.second + c.second - a.second
       << "\n";
  return 0;
}
