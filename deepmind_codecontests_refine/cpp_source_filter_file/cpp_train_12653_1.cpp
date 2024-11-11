#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int inf = ((1LL << 31) - 10);
struct Rmq {
  int d[maxn][25];
  int mode;
  void RMQ_init(const vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; i++) d[i][0] = A[i];
    for (int j = 1; (1 << j) <= n; j++)
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        int tmp = d[i + (1 << (j - 1))][j - 1];
        if (mode == 1)
          d[i][j] = max(d[i][j - 1], tmp);
        else
          d[i][j] = min(d[i][j - 1], tmp);
      }
  }
  long long RMQ(int L, int R) {
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++;
    if (mode == 1)
      return max(d[L][k], d[R - (1 << k) + 1][k]);
    else
      return min(d[L][k], d[R - (1 << k) + 1][k]);
  }
} a, b;
vector<int> s;
int main() {
  int n;
  scanf("%d", &n);
  a.mode = 1, b.mode = -1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    s.push_back(x);
  }
  a.RMQ_init(s);
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  b.RMQ_init(s);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int r = n - 1, l = i;
    while (l < r) {
      int m = (l + r) / 2;
      int qa = a.RMQ(l, m), qb = b.RMQ(l, m);
      if (qa > qb)
        r = m - 1;
      else if (qa < qb)
        l = m + 1;
      else
        r = m;
    }
    if (l != r || (a.RMQ(i, l) != b.RMQ(i, l))) continue;
    int ansl = l;
    r = n - 1, l = i;
    while (l < r) {
      int m = (l + r + 1) / 2;
      int qa = a.RMQ(l, m), qb = b.RMQ(l, m);
      if (qa > qb)
        r = m - 1;
      else if (qa < qb)
        l = m + 1;
      else
        l = m;
    }
    if (l != r || (a.RMQ(i, l) != b.RMQ(i, l))) continue;
    ans += l - ansl + 1;
  }
  cout << ans << endl;
  return 0;
}
