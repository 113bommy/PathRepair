#include <bits/stdc++.h>
int read() {
  int f = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  do f = 10 * f + (ch ^ '0');
  while (isdigit(ch = getchar()));
  return f;
}
const int N_MAX = 100003;
int n, m, k, p, h[N_MAX], a[N_MAX];
long long c[N_MAX];
struct Data {
  int id, day;
  Data() {}
  Data(int id, int day) : id(id), day(day) {}
  friend bool operator<(const Data &lhs, const Data &rhs) {
    return lhs.day > rhs.day;
  }
};
bool check(long long now) {
  std::priority_queue<Data> que;
  for (int i = 1; i <= n; ++i) {
    c[i] = now;
    if (c[i] - 1ll * m * a[i] < h[i]) que.push(Data(i, c[i] / a[i]));
  }
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= k && !que.empty(); ++j) {
      Data x = que.top();
      if (i > x.day) return 0;
      que.pop();
      c[x.id] += p;
      if (c[x.id] - 1ll * m * a[x.id] < h[x.id])
        que.push(Data(x.id, c[x.id] / a[x.id]));
    }
  return que.empty();
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  long long l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    h[i] = read(), a[i] = read();
    l = std::max(l, (long long)h[i]), r = std::max(r, 1ll * m * a[i] + h[i]);
  }
  while (l < r) {
    long long mid = (l + r) >> 1;
    check(mid) ? r = mid : l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
