#include <bits/stdc++.h>
using namespace std;
int n;
int ap[5005], best[5005], cnt[5005];
int d[5005][5005];
void read() {
  scanf("%d", &n);
  int x;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    ++ap[x];
  }
}
void prec() {
  best[1] = 1;
  for (int i = 2; i <= 5000; ++i) {
    int x = i;
    d[i][1] = 1;
    cnt[i] += cnt[i - 1];
    for (int j = 2; j <= 5000; ++j) {
      while (x % j == 0) {
        x /= j;
        ++d[i][j];
        ++cnt[i];
      }
      d[i][j] += d[i - 1][j];
      if (d[i][j]) best[i] = j;
    }
  }
}
int f[5005];
struct fact {
  int x, ap, p;
};
vector<fact> v;
vector<fact> v2;
void solve() {
  long long Sol = 0;
  for (int i = 2; i <= 5000; ++i) {
    if (ap[i]) {
      Sol = Sol + 1LL * ap[i] * cnt[i];
      v.push_back({i, ap[i], best[i]});
    }
  }
  while (!v.empty()) {
    memset(f, 0, sizeof(f));
    for (auto it : v) f[best[it.x]] += (it.ap);
    int Max = 0, prim = 0;
    for (int i = 2; i <= 5000; ++i) {
      if (f[i] > Max) Max = f[i], prim = i;
    }
    if (Max <= n - Max) break;
    Sol = Sol - Max + (n - Max);
    v2.clear();
    for (auto it : v) {
      if (it.p != prim) continue;
      int p = it.p;
      --d[it.x][p];
      if (d[it.x][p])
        v2.push_back({it.x, it.ap, p});
      else {
        while (p > 1 && d[it.x][p] == 0) --p;
        if (p > 1) v2.push_back({it.x, it.ap, p});
      }
    }
    swap(v, v2);
  }
  printf("%lld", Sol);
}
int main() {
  read();
  prec();
  solve();
}
