#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, val[maxn], m;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
struct Ask {
  int x, y, id;
  long long ans;
} a[maxn];
bool cmp(Ask a, Ask b) { return a.y < b.y; }
bool cmp1(Ask a, Ask b) { return a.id < b.id; }
vector<long long> sum[600];
void solve(int st, int ed, int w) {
  for (int i = 0; i < w; i++) sum[i].clear(), sum[i].push_back(0);
  for (int i = 1; i <= n; i++) {
    int x = *--sum[i % w].end();
    sum[i % w].push_back(x + val[i]);
  }
  for (int i = st; i <= ed; i++) {
    int yu = a[i].x % w;
    int size = n / w + ((n % w) >= yu && yu);
    int size1 = (a[i].x + w - 1) / w;
    a[i].ans = sum[yu][size] - sum[yu][size1 - 1];
  }
  return;
}
void solve(int id) {
  int pos = a[id].x;
  while (pos <= n) {
    a[id].ans += val[pos];
    pos += a[id].y;
  }
  return;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    val[i] = read();
  }
  m = read();
  for (int i = 1; i <= m; i++) {
    a[i].x = read();
    a[i].y = read();
    a[i].id = i;
  }
  sort(a + 1, a + m + 1, cmp);
  int limit = sqrt(n);
  int tp = 1;
  while (tp <= m) {
    if (a[tp].y > limit) break;
    int pos = tp;
    while (a[tp].y == a[tp + 1].y) {
      tp++;
    }
    solve(pos, tp, a[tp].y);
    tp++;
  }
  for (int i = tp; i <= m; i++) {
    solve(i);
  }
  sort(a + 1, a + m + 1, cmp1);
  for (int i = 1; i <= m; i++) {
    printf("%lld\n", a[i].ans);
  }
  return 0;
}
