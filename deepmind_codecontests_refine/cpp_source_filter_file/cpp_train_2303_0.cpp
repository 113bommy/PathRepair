#include <bits/stdc++.h>
int n, m, Q;
int v[233333];
bool tf[233333];
int tp[233333];
void work(int *w, int len, int mx) {
  for (int i = 1; i <= len; i++) tp[i] = w[i], tf[i] = true;
  for (int i = 1; i < mx; i++) tf[len + i] = false;
  tf[len + mx] = true;
  for (int i = len; i; i--) {
    if (tp[i] & 1) {
      for (int j = 1; j <= m; j++)
        if (tf[i + j]) tf[i] = false;
    } else
      tf[i] = false;
  }
}
int mxb;
int be[233333];
int bg[6666];
int ed[6666];
int g[6666];
int f[6666][2][7];
void rework(int a) {
  for (int j = 1; j <= 6; j++) {
    work(v + bg[a] - 1, ed[a] - bg[a] + 1, j);
    for (int k = 1; k <= 5; k++) {
      if (!tf[k]) {
        f[a][0][j] = k;
        break;
      }
      if (k == 5) f[a][0][j] = 6;
    }
  }
  for (int j = bg[a]; j <= ed[a]; j++) v[j] ^= 1;
  for (int j = 1; j <= 6; j++) {
    work(v + bg[a] - 1, ed[a] - bg[a] + 1, j);
    for (int k = 1; k <= 5; k++) {
      if (!tf[k]) {
        f[a][1][j] = k;
        break;
      }
      if (k == 5) f[a][1][j] = 6;
    }
  }
  for (int j = bg[a]; j <= ed[a]; j++) v[j] ^= 1;
}
void clear(int b) {
  if (g[b]) {
    g[b] = 0;
    for (int i = bg[b]; i <= ed[b]; i++) v[i] ^= 1;
  }
}
void rebuild(int b, int l, int r) {
  clear(b);
  for (int i = l; i <= r; i++) v[i] ^= 1;
  rework(b);
}
int main() {
  scanf("%d %d %d", &n, &m, &Q);
  long long rd;
  for (int i = 1; i <= n; i++) scanf("%lld", &rd), v[i] = (rd & 1) ? 1 : 0;
  mxb = n / 56;
  if (n % 56) mxb++;
  for (int i = 1; i <= mxb; i++) bg[i] = (i - 1) * 56 + 1, ed[i] = i * 56;
  ed[mxb] = n;
  for (int i = 1; i <= n; i++) be[i] = (i - 1) / 56 + 1;
  for (int i = 1; i <= mxb; i++) rework(i);
  for (int i = 1, op, l, r, bl, br; i <= Q; i++) {
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1) {
      scanf("%lld", &rd);
      if (rd & 1) {
        bl = be[l], br = be[r];
        for (int j = bl + 1; j < br; j++) g[j] ^= 1;
        if (bl == br)
          rebuild(bl, l, r);
        else
          rebuild(bl, l, ed[bl]), rebuild(br, bg[br], r);
      }
    } else {
      bl = be[l], br = be[r];
      if (bl == br)
        rebuild(bl, 0, 0);
      else
        rebuild(bl, 0, 0), rebuild(br, 0, 0);
      if (r - l <= 56) {
        work(v + l - 1, r - l, (v[r]) ? 1 : 6);
        if (tf[1])
          puts("2");
        else
          puts("1");
      } else {
        work(v + bg[br] - 1, r - bg[br], (v[r]) ? 1 : 6);
        int now;
        for (int k = 1; k <= 5; k++) {
          if (!tf[k]) {
            now = k;
            break;
          }
          if (k == 5) now = 6;
        }
        for (int j = br - 1; j > bl; j--) now = f[j][g[j]][now];
        work(v + l - 1, ed[bl] - l + 1, now);
        if (tf[1])
          puts("2");
        else
          puts("1");
      }
    }
  }
  return 0;
}
