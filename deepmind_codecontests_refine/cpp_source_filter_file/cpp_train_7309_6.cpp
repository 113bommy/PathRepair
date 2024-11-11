#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= op;
}
template <typename Tp>
void CMax(Tp &x, Tp y) {
  if (y > x) x = y;
}
template <typename Tp>
void CMin(Tp &x, Tp y) {
  if (y < x) x = y;
}
int n, k, ans;
bool vis[N];
vector<int> c[N];
void add(int x) {
  for (int i = 0; i < (int)c[x].size(); ++i) {
    printf("? %d\n", c[x][i]);
    fflush(stdout);
    char ch;
    cin >> ch;
    if (ch == 'Y') vis[c[x][i]] = 1;
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int B = max(1, k / 2);
  int cnt = n / B;
  for (int i = (1); i <= (cnt); ++i)
    for (int j = ((i - 1) * B + 1); j <= (i * B); ++j) c[i].push_back(j);
  for (int d = (1); d <= (cnt - 1); ++d) {
    for (int i = (1); i <= (d); ++i) {
      if (i + d > n) {
        printf("R\n");
        fflush(stdout);
        break;
      }
      for (int j = i; j <= n; j += d) {
        add(j);
      }
      printf("R\n");
      fflush(stdout);
    }
  }
  for (int i = (1); i <= (n); ++i)
    if (!vis[i]) ans++;
  printf("! %d", ans);
  fflush(stdout);
  return 0;
}
