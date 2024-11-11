#include <bits/stdc++.h>
using namespace std;
int n, k, t;
int pcnt = 0, pri[100000];
bool isp[1000000];
void getprime(void) {
  memset(isp, 1, sizeof(isp));
  for (int i = 2; i < 1000000; i++)
    if (isp[i]) {
      pri[pcnt++] = i;
      for (int j = 2; i * j < 1000000; j++) isp[i * j] = 0;
    }
  return;
}
struct num {
  int fac[10], cnt;
} arr[100000];
int f[10000000];
void add(int i, int pos, int S) {
  if (pos == arr[i].cnt) {
    if (S != 1) f[S]++;
    return;
  }
  add(i, pos + 1, S);
  add(i, pos + 1, S * arr[i].fac[pos]);
  return;
}
void del(int i, int pos, int S) {
  if (pos == arr[i].cnt) {
    if (S != 1) f[S]--;
    return;
  }
  del(i, pos + 1, S);
  del(i, pos + 1, S * arr[i].fac[pos]);
  return;
}
void read(void) {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    arr[i].cnt = 0;
    for (int j = 0; pri[j] * pri[j] <= t; j++)
      if (t % pri[j] == 0) {
        arr[i].fac[arr[i].cnt++] = pri[j];
        while (t % pri[j] == 0) t /= pri[j];
      }
    if (t > 1) arr[i].fac[arr[i].cnt++] = t;
    if (i < 2 * k) add(i, 0, 1);
  }
  n = 2 * k;
  return;
}
int deg[100000], F = -1, G = -1, H = -1;
int getdeg(int i, int pos, int S, int opt) {
  if (pos == arr[i].cnt) return opt * f[S];
  return getdeg(i, pos + 1, S, opt) +
         getdeg(i, pos + 1, S * arr[i].fac[pos], -opt);
}
inline bool common(int a, int b) {
  int i = 0, j = 0;
  while (i <= arr[a].cnt && j <= arr[j].cnt) {
    if (arr[a].fac[i] == arr[b].fac[j]) return 1;
    if (arr[a].fac[i] > arr[b].fac[j])
      j++;
    else
      i++;
  }
  return 0;
}
void getFGH(int i) {
  F = i;
  for (int j = 0; j < n; j++)
    if (!common(i, j)) {
      if (G == -1)
        G = j;
      else if (H == -1)
        H = j;
    }
  return;
}
void solve1(void) {
  for (int i = 0; i < n; i++) del(i, 0, 1);
  int cnt = 0;
  for (int i = 0; i < n && cnt < k; i++)
    if (getdeg(i, 0, 1, -1) == cnt) {
      cnt++;
      printf("%d ", i + 1);
      add(i, 0, 1);
    }
  return;
}
int check(int m) {
  int m0 = m + 1;
  for (int i = 0; i <= m; i++)
    if (i != F && i != G && i != H)
      add(i, 0, 1);
    else
      m0--;
  int x = 0;
  for (int i = 0; i <= m; i++) {
    if (i == F || i == G || i == H) continue;
    deg[i] = m0 - getdeg(i, 0, 1, -1);
    if (deg[i] > 0) x++;
  }
  return x;
}
void solve2(void) {
  for (int i = 0; i < n; i++)
    if (i != F && i != G && i != H) del(i, 0, 1);
  int l = k - 4, r = n - 2, m;
  while (l < r) {
    m = (l + r + 1) >> 1;
    if (check(m) >= k - 3)
      r = m - 1;
    else
      l = m;
    for (int i = 0; i <= m; i++)
      if (i != F && i != G && i != H) del(i, 0, 1);
  }
  m = l + 1;
  int p = check(m);
  if (p >= k) {
    for (int i = 0; i < m && p > k; i++)
      if (i != F && i != G && i != H && deg[i] == 1 && !common(i, m)) {
        p--;
        deg[i] = -1;
      }
  } else {
    for (int i = 0; i < m && p > k - 2; i++)
      if (i != F && i != G && i != H && deg[i] == 1 && !common(i, m)) {
        p--;
        deg[i] = -1;
      }
    printf("%d %d ", F + 1, G + 1);
    if (p == k - 3) printf("%d ", H + 1);
  }
  for (int i = 0; i <= m; i++)
    if (i != F && i != G && i != H && deg[i] > 0) printf("%d ", i + 1);
  return;
}
int main(void) {
  getprime();
  read();
  int w = 0;
  for (int i = 0; i < n; i++) {
    deg[i] = getdeg(i, 0, 1, -1);
    if (deg[i] < n) w++;
    if (F == -1 && deg[i] <= n - 2) getFGH(i);
  }
  if (F == -1) {
    solve1();
    return 0;
  }
  for (int i = 0; i < n; i++) del(i, 0, 1);
  if (check(n - 1) < k - 3) {
    for (int i = 0; i < n && k > 0; i++)
      if (deg[i] == 0) {
        printf("%d ", i + 1);
        k--;
      }
  } else
    solve2();
  return 0;
}
