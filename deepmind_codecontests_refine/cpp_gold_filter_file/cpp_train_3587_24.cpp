#include <bits/stdc++.h>
using namespace std;
struct rmqf {
  long long s[1501 << 2];
  inline long long operator[](int i) { return s[i]; }
  inline void operator=(const rmqf &b) {
    for (int j = 0; j < 1501 << 2; ++j) s[j] = b.s[j];
  }
};
const int maxn = 2000;
int n, gm;
rmqf a, b;
long long sum[maxn][maxn];
int p;
void insert(rmqf &rmq, int i, long long s) {
  int l = 1, r = gm, m, id = 1;
  while (l < r) {
    m = (l + r) >> 1;
    if (i <= m)
      r = m, id <<= 1;
    else
      l = m + 1, id = (id << 1) | 1;
  }
  rmq.s[id] = s;
  id >>= 1;
  while (id >= 1) {
    rmq.s[id] = max(rmq[id << 1], rmq[(id << 1) | 1]);
    id >>= 1;
  }
}
long long getmax(rmqf &rmq, int i, int l, int r, int nl, int nr) {
  if ((nl == l) && (nr == r))
    return rmq[i];
  else {
    int m = (l + r) >> 1;
    if (nr <= m)
      return getmax(rmq, i << 1, l, m, nl, nr);
    else if (nl > m)
      return getmax(rmq, (i << 1) | 1, m + 1, r, nl, nr);
    else
      return max(getmax(rmq, i << 1, l, m, nl, m),
                 getmax(rmq, (i << 1) | 1, m + 1, r, m + 1, nr));
  }
}
int main() {
  int k, w, l, f, t, nmb;
  cin >> n >> gm;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= gm; ++j) {
      scanf("%d", &p);
      sum[i][j] = p;
      sum[i][j] += sum[i][j - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= gm; ++j)
      if ((i % 2) == 0) {
        if (i == 1)
          insert(b, j, sum[i][j]);
        else if (j + 1 <= gm)
          insert(b, j, getmax(a, 1, 1, gm, j + 1, gm) + sum[i][j]);
        else
          insert(b, j, -10000000000000000ll);
      } else {
        if (i == 1)
          insert(b, j, sum[i][j]);
        else if (1 <= j - 1)
          insert(b, j, getmax(a, 1, 1, gm, 1, j - 1) + sum[i][j]);
        else
          insert(b, j, -10000000000000000ll);
      }
    a = b;
  }
  cout << a[1] << endl;
}
