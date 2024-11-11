#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
const int N = 100005;
int n, m, p, h[N], a[N], top[103], run[103];
long long sum[N], cur;
pair<int, long long> q[103][N];
long long get(int type, int A) {
  if (run[type] > top[type]) run[type] = top[type];
  while (run[type] < top[type] &&
         1ll * A * q[type][run[type]].first + q[type][run[type]].second >
             1ll * A * q[type][run[type] + 1].first +
                 q[type][run[type] + 1].second)
    ++run[type];
  return 1ll * A * q[type][run[type]].first + q[type][run[type]].second;
}
bool Check(pair<int, long long> l1, pair<int, long long> l2,
           pair<int, long long> l3) {
  return 1.0 * (l1.second - l2.second) / (l2.first - l1.first) >=
         1.0 * (l1.second - l3.second) / (l3.first - l1.first);
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  read(n);
  read(m);
  read(p);
  if (m <= p) return write(0), 0;
  for (int i = 2; i <= n; ++i) {
    int x;
    read(x);
    h[i] = h[i - 1] + x;
  }
  for (int i = 1; i <= m; ++i) {
    int x, y;
    read(x);
    read(y);
    a[i] = y - h[x];
  }
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= m; ++i) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= min(p, i); ++j) {
      cur = get(j - 1, a[i]) - sum[i] + 1ll * a[i] * i;
      if (j < p) {
        while (top[j] && Check(q[j][top[j] - 1], q[j][top[j]],
                               make_pair(-i, cur + sum[i - 1])))
          --top[j];
        q[j][++top[j]] = make_pair(-i, cur + sum[i - 1]);
      }
    }
  write(cur);
}
