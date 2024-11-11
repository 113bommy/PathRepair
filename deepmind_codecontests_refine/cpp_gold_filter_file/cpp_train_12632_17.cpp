#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7, BASE = 1e9;
const int N = 5e3 + 10;
int ans[N], n, pos[N][2], h[N] = {0};
pair<int, int> a[N];
char s[6];
struct bnum {
  int a[120];
  bnum(int x = 0) {
    memset(a, 0, sizeof(a));
    a[0] = 1;
    a[1] = x;
  }
  void print() {
    printf("%d", a[a[0]]);
    for (auto i = a[0] - 1; i >= 1; i--) {
      for (int j = BASE / 10; j > 1 && j > a[i]; j /= 10) printf("0");
      printf("%d", a[i]);
    }
  }
};
bnum operator+(bnum x, bnum y) {
  x.a[0] = max(x.a[0], y.a[0]);
  for (auto i = 1; i <= x.a[0]; i++) {
    x.a[i] += y.a[i];
    x.a[i + 1] += x.a[i] / BASE;
    x.a[i] %= BASE;
  }
  x.a[0] += (x.a[x.a[0] + 1] > 0);
  return x;
}
int main() {
  scanf("%d", &n);
  for (auto i = 1; i <= n; i++) {
    scanf("\n%s%d", s, &a[i].second);
    a[i].first = (s[0] == 's');
    pos[a[i].second][a[i].first] = i;
  }
  h[0] = 1;
  for (auto i = 2000; i >= 0; i--)
    if (pos[i][1]) {
      for (auto j = pos[i][1] - 1; j >= 1; j--)
        if (a[j].second == i) {
          pos[i][0] = j;
          break;
        }
      bool ok = pos[i][0] < pos[i][1];
      for (auto j = pos[i][0]; j <= pos[i][1]; j++)
        if (h[j]) ok = false;
      if (ok) {
        ans[i] = 1;
        for (auto j = pos[i][0]; j <= pos[i][1]; j++) h[j] = 1;
      }
    }
  bnum tmp = bnum(1), ret;
  for (auto i = 0; i <= 2000; i++) {
    if (ans[i]) ret = ret + tmp;
    tmp = tmp + tmp;
  }
  ret.print();
}
