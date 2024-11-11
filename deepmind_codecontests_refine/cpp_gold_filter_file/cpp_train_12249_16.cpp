#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int a[N], prime[N], idx, temp[N], n;
bool vis[N], st[N];
int check(int x) {
  int res = 0;
  for (int i = x + 1; i < N; i++) {
    bool flag = true;
    int t = i;
    for (int j = 2; j <= t / j; j++) {
      if (t % j == 0) {
        if (st[j]) flag = false;
        while (t % j == 0) t /= j;
      }
    }
    if (t > 1 && st[t]) flag = false;
    if (flag) {
      int res = i;
      for (int j = 2; j <= i / j; j++) {
        if (i % j == 0) {
          st[j] = true;
          while (i % j == 0) i /= j;
        }
      }
      if (i > 1) st[i] = true;
      return res;
    }
  }
}
void solve(int pos) {
  for (int i = 1; i < pos; i++) printf("%d ", temp[i]);
  printf("%d ", check(temp[pos]));
  int res = 0;
  for (int i = pos + 1; i <= n; i++) {
    while (st[prime[res]]) res++;
    printf("%d ", prime[res++]);
  }
  return;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  memcpy(temp, a, sizeof a);
  vis[1] = true;
  for (int i = 2; i < N; i++) {
    if (!vis[i]) prime[idx++] = i;
    for (int j = 0; i < N / prime[j]; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 1; i <= n; i++) {
    int ts = a[i];
    for (int j = 2; j <= a[i] / j; j++) {
      if (a[i] % j == 0) {
        if (st[j]) {
          solve(i);
          return 0;
        }
        while (a[i] % j == 0) a[i] /= j;
      }
    }
    if (a[i] > 1) {
      if (st[a[i]]) {
        solve(i);
        return 0;
      }
      st[a[i]] = true;
    }
    for (int j = 2; j <= ts / j; j++) {
      if (ts % j == 0) {
        st[j] = true;
        while (ts % j == 0) ts /= j;
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", temp[i]);
  return 0;
}
