#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmx(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void ckmi(T &x, T y) {
  x = min(x, y);
}
void read() {}
template <typename T, typename... Ts>
void read(T &x, Ts &...args) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
  read(args...);
}
int n, k, c[10010];
int ax[110], ay[110];
vector<int> ps[110];
int nw[110], mx;
int main() {
  read(n, k);
  mx = (n + k - 2) / (k - 1);
  for (int i = 1; i <= n * k; ++i) {
    read(c[i]);
    ps[c[i]].push_back(i);
  }
  int cnt = 0, nc = 1;
  for (int i = 1; i <= n * k; ++i) {
    int x = c[i];
    if (!ax[x]) {
      if (nw[x] == nc) {
        ax[x] = ps[x][nw[x] - 1];
        ay[x] = ps[x][nw[x]];
        cnt++;
        if (cnt == mx) cnt = 0, nc++;
      }
      nw[x]++;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d %d\n", ax[i], ay[i]);
  return 0;
}
