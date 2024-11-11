#include <bits/stdc++.h>
using namespace std;
const int MAXN = 19;
char L[MAXN + 5], R[MAXN + 5];
int x[MAXN + 5], y[MAXN + 5];
int c[10], cc[10];
bool check_less(int i, int nz) {
  if (i == MAXN) {
    if (nz > 0)
      return false;
    else
      return true;
  }
  for (int j = 0; j < y[i]; j++) {
    if (cc[j] > 0) {
      if (MAXN - i >= nz)
        return true;
      else
        return false;
    }
  }
  if (cc[y[i]] > 0) {
    cc[y[i]]--;
    nz--;
    bool ok = check_less(i + 1, nz);
    cc[y[i]]++;
    nz++;
    return ok;
  } else
    return false;
}
bool check_more(int i, int nz) {
  if (i == MAXN) {
    if (nz > 0)
      return false;
    else
      return true;
  }
  for (int j = x[i] + 1; j < 10; j++) {
    if (cc[j] > 0) {
      if (MAXN - i >= nz)
        return true;
      else
        return false;
    }
  }
  if (cc[x[i]] > 0) {
    cc[x[i]]--;
    nz--;
    bool ok = check_more(i + 1, nz);
    cc[x[i]]++;
    nz++;
    return ok;
  } else
    return false;
}
bool check() {
  memcpy(cc, c, sizeof c);
  int nz = 0;
  for (int i = 0; i < 10; i++) nz += cc[i];
  for (int i = 0; i < MAXN; i++) {
    if (x[i] == y[i]) {
      if (cc[x[i]] == 0) return false;
      cc[x[i]]--;
      nz--;
    } else {
      for (int j = x[i] + 1; j < y[i]; j++) {
        if (cc[j] > 0) {
          if (MAXN - i >= nz)
            return true;
          else
            return false;
        }
      }
      if (cc[x[i]] > 0) {
        cc[x[i]]--;
        nz--;
        if (check_more(i + 1, nz)) return true;
        cc[x[i]]++;
        nz++;
      }
      if (cc[y[i]] > 0) {
        cc[y[i]]--;
        nz--;
        if (check_less(i + 1, nz)) return true;
        cc[y[i]]++;
        nz++;
      }
      return false;
    }
  }
  for (int i = 0; i < 10; i++)
    if (cc[i] > 0) return false;
  return true;
}
int solve(int i, int d) {
  if (i == MAXN) {
    if (check())
      return 1;
    else
      return 0;
  } else {
    int r = 0;
    c[d]++;
    r += solve(i + 1, d);
    c[d]--;
    if (d < 9) r += solve(i, d + 1);
    return r;
  }
}
int main() {
  scanf("%s %s", L, R);
  int n = strlen(L);
  int m = strlen(R);
  reverse(L, L + n);
  reverse(R, R + m);
  for (int i = 0; i < MAXN; i++) {
    if (i < n)
      x[i] = L[i] - '0';
    else
      x[i] = 0;
    if (i < m)
      y[i] = R[i] - '0';
    else
      y[i] = 0;
  }
  reverse(x, x + MAXN);
  reverse(y, y + MAXN);
  printf("%d\n", solve(0, 0));
  return 0;
}
