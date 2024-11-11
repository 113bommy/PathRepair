#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  x *= f;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x *= f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
const int N = 3e5 + 5;
int n, m;
int a[N];
long long ans[N], sum[N + 5000];
struct node {
  int b, k, id;
  bool operator<(node x) const { return k < x.k; }
} ask[N];
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  read(m);
  for (int i = 1; i <= m; ++i) {
    read(ask[i].b);
    read(ask[i].k);
    ask[i].id = i;
  }
  sort(ask + 1, ask + 1 + m);
  int t = sqrt(n);
  int i = 1;
  for (i = 1; i <= m && ask[i].k <= t; ++i) {
    int tmp = ask[i].k;
    for (int k = n; k >= 1; --k) sum[k] = sum[k + tmp] + a[k];
    int j = i;
    while (j <= m) {
      ans[ask[j].id] = sum[ask[j].b];
      if (ask[j + 1].k != ask[i].k) break;
      ++j;
    }
    i = j;
  }
  for (; i <= m; ++i) {
    int k = ask[i].k;
    long long tmp = 0;
    for (int j = ask[i].b; j <= n; j += k) tmp += a[j];
    ans[ask[i].id] = tmp;
  }
  for (int i = 1; i <= m; ++i) print(ans[i]), putchar('\n');
  return 0;
}
