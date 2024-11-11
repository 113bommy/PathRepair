#include <bits/stdc++.h>
int l[5000010], r[5000010];
int lyndon(char zf[5000010], int n) {
  int i = 0, j = 0, k = 1, ans = 0, m = 0;
  while (i < n) {
    if (zf[k] == zf[j])
      j += 1, k += 1;
    else if (zf[k] > zf[j])
      j = i, k += 1;
    else {
      int l = k - j;
      while (i <= j) {
        ::l[m] = i;
        r[m++] = i + l - 1;
        i += l;
      }
      j = i;
      k = i + 1;
    }
  }
  return m;
}
char zf[5000010], od[5000010];
bool same(int a, int b, int l, int r) {
  if (b - a != r - l) return false;
  for (int i = a, j = l; i <= b; i++, j++) {
    if (zf[i] != zf[j]) return false;
  }
  return true;
}
bool same(int i, int j) { return same(l[i], r[i], l[j], r[j]); }
void output(int l, int r, bool rev = false) {
  if (rev) {
    for (int i = r; i >= l; i--) printf("%c", zf[i]);
  } else {
    for (int i = l; i <= r; i++) printf("%c", zf[i]);
  }
}
void strrev(char zf[5000010]) {
  int n = strlen(zf);
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    char t = zf[i];
    zf[i] = zf[j];
    zf[j] = t;
  }
}
char db[10000010];
int zxbsf(char zf[5000010], int n) {
  for (int i = 0; i < n; i++) db[i] = db[i + n] = zf[i];
  int i = 0, j = 1, k;
  while (i < n && j < n) {
    for (k = 0; k < n && db[i + k] == db[j + k]; k++)
      ;
    if (k == n) break;
    char a = db[i + k], b = db[j + k];
    if (a > b)
      i += k + 1;
    else
      j += k + 1;
    if (i == j) j += 1;
  }
  return i < j ? i : j;
}
char jg[5000010], tm[5000010];
int bl[5000010], ne[10000010];
int strcmp(int x, int y, int r) {
  int i, j;
  for (i = bl[x], j = bl[y]; i <= r && j <= r; i++, j++) {
    if (zf[i] != zf[j]) return zf[i] - zf[j];
  }
  for (i = bl[x] - 1; j <= r; i--, j++) {
    if (zf[i] != zf[j]) return zf[i] - zf[j];
  }
  return 0;
}
int getlcp(char zf[10000010], int x, int y) {
  int jg = 0;
  while (zf[x + jg] == zf[y + jg]) jg += 1;
  return jg;
}
void exkmp(char zf[10000010], int n) {
  ne[0] = n;
  ne[1] = getlcp(zf, 0, 1);
  int k = 1, p = k + ne[k] - 1;
  for (int i = 2; i < n; i++) {
    int L = ne[i - k];
    if (i + L <= p)
      ne[i] = L;
    else {
      int z = p - i + 1;
      if (z < 0) z = 0;
      while (zf[z] == zf[i + z]) z += 1;
      ne[i] = z;
      k = i;
      p = k + z - 1;
    }
  }
}
void split(int r, int n, int m) {
  int w = zxbsf(zf, r + 1);
  zf[r + 1] = 0;
  strcpy(jg, zf);
  for (int i = 0; i <= r; i++) tm[i] = zf[(w + i) % (r + 1)];
  if (strcmp(tm, jg) < 0) strcpy(jg, tm);
  int k = 0, la = 0;
  for (int i = 0; i <= m; i++) {
    if (i > 0 && !same(i, i - 1)) {
      bl[k++] = la;
      la = ::r[i - 1] + 1;
    }
  }
  bl[k++] = la;
  while (k > 0) {
    if (strcmp(k, k - 1, r) < 0) break;
    k -= 1;
  }
  for (int i = bl[k]; i <= r; i++) tm[i - bl[k]] = zf[i];
  for (int i = bl[k] - 1, j = r + 1 - bl[k]; i >= 0; i--, j++) tm[j] = zf[i];
  if (strcmp(tm, jg) < 0) strcpy(jg, tm);
  int z = n - 1 - r;
  for (int i = z; i < n; i++) zf[i - z] = od[i];
  n -= z;
  zf[n] = 0;
  strcpy(tm, zf);
  if (strcmp(tm, jg) < 0) strcpy(jg, tm);
  strcpy(db, zf);
  strrev(db);
  for (int i = 0; i < n; i++) db[i + n] = zf[i];
  exkmp(db, n + n);
  int wz = 0;
  for (int i = 1; i < n; i++) {
    int z = ne[n + wz + 1];
    if (z < i - wz) {
      if (zf[wz + z + 1] < db[z]) wz = i;
      continue;
    }
    z = ne[i - wz];
    if (i + 1 + z < n && db[z] < db[i - wz + z]) wz = i;
  }
  for (int i = 0; i <= wz; i++) tm[i] = zf[i];
  for (int i = n - 1, j = wz + 1; i > wz; i--, j++) tm[j] = zf[i];
  if (strcmp(tm, jg) < 0) strcpy(jg, tm);
  printf("%s", jg);
}
void solve(int n, int k) {
  int m = lyndon(zf, n) - 1;
  while (k > 2 && m >= 0) {
    int zm = m;
    while (zm > 0 && same(m, zm - 1)) zm -= 1;
    k -= 1;
    output(l[zm], r[m]);
    if (zm > 0 && r[m] == l[m] && r[zm - 1] == l[zm - 1]) k += 1;
    m = zm - 1;
  }
  if (m < 0) return;
  split(r[m], n, m);
}
int main() {
  int n, k;
  scanf("%s%d", od, &k);
  n = strlen(od);
  for (int i = 0; i < n; i++) zf[n - i - 1] = od[i];
  if (k == 1) {
    if (strcmp(zf, od) < 0)
      printf("%s", zf);
    else
      printf("%s", od);
    return 0;
  }
  solve(n, k);
  return 0;
}
