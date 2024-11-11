#include <bits/stdc++.h>
const int MAXN = 3e5 + 10;
const double eps = 1e-8;
using namespace std;
struct edge {
  int t, v;
  edge *next;
} e[MAXN << 1], *h[MAXN], *o = e;
void add(int x, int y, int vul) {
  o->t = y;
  o->v = vul;
  o->next = h[x];
  h[x] = o++;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
int _, n, k;
int num[5005];
int f[MAXN];
vector<int> vec[MAXN];
int main() {
  _ = read();
  while (_--) {
    n = read();
    k = read();
    for (int i = 1; i <= n; i++) vec[i].clear(), f[i] = num[i] = 0;
    int x = 1ll * (n - 1) * n / 2;
    int dep = 0;
    int m = n;
    for (int i = 1; i <= m; i++) {
      if (n > (1 << (i - 1)))
        num[i] = (1 << (i - 1)), n -= (1 << (i - 1)),
        dep += 1ll * (i - 1) * num[i];
      else {
        num[i] = n;
        dep += 1ll * (i - 1) * num[i];
        break;
      }
    }
    if (k < dep || k > x)
      puts("NO");
    else {
      for (int i = dep + 1; i <= k; i++) {
        for (int j = 5000; j >= 1; j--) {
          if (num[j] <= 1) continue;
          num[j]--;
          num[j + 1]++;
          break;
        }
      }
      puts("YES");
      vec[1].push_back(1);
      int tot = 1;
      for (int i = 2; i <= 5000; i++) {
        if (!num[i]) break;
        int cnt = 0;
        int l = 0;
        for (int j = tot + 1; j <= tot + num[i]; j++) {
          f[j] = vec[i - 1][l];
          cnt++;
          vec[i].push_back(j);
          if (cnt == 2) cnt = 0, l++;
        }
        tot += num[i];
      }
      for (int i = 2; i <= tot; i++) printf("%d ", f[i]);
      printf("\n");
    }
  }
  return 0;
}
