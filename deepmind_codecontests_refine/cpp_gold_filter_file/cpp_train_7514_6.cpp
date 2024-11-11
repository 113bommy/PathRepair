#include <bits/stdc++.h>
using namespace std;
const int N = 3605;
const long long MOD = 998244353;
int n, m, k;
int bla[N], blaa[N];
vector<int> r, s;
long long a[N][N], b[N][N];
long long res = 0;
long long fakt[N];
long long dijeli[N];
long long fastpot(long long x, long long b) {
  long long ret = 1;
  for (int i = 0; i < 32; i++) {
    if (b & (1 << i)) ret *= x;
    x *= x;
    ret %= MOD;
    x %= MOD;
  }
  return ret;
}
long long povrh(int x, int y) {
  if (y < x) return 0;
  long long ret = 1;
  ret *= fakt[y];
  ret *= dijeli[y - x];
  ret %= MOD;
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  fakt[0] = 1;
  for (int i = 1; i < N; i++) {
    fakt[i] = fakt[i - 1] * i;
    fakt[i] %= MOD;
  }
  for (int i = 0; i < N; i++) {
    dijeli[i] = fastpot(fakt[i], MOD - 2);
  }
  for (int i = 0; i < k; i++) {
    int a1, a2, a3, a4;
    scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
    a1--;
    a2--;
    a3--;
    a4--;
    bla[a1]++;
    bla[a3]++;
    blaa[a2]++;
    blaa[a4]++;
  }
  for (int i = 0; i < n; i++) {
    if (bla[i] == 0) r.push_back(i);
  }
  for (int i = 0; i < m; i++) {
    if (blaa[i] == 0) s.push_back(i);
  }
  for (int i = 0; i < N; i++) {
    a[0][i] = 1;
    b[0][i] = 1;
  }
  if (r.size() <= 1 && s.size() <= 1) {
    cout << 1;
    return 0;
  }
  if (r.size() == 0 || s.size() == 0) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < r.size() - 1; j++) {
      if (j <= 1) {
        if (r[j] == r[j + 1] - 1 && i == 1) a[i][j] = 1;
      }
      if (j > 0) {
        a[i][j] += a[i][j - 1];
      }
      if (j > 1) {
        if (r[j] == r[j + 1] - 1) a[i][j] += a[i - 1][j - 2];
      }
      if (a[i][j] >= MOD) a[i][j] -= MOD;
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < s.size() - 1; j++) {
      if (j <= 1) {
        if (s[j] == s[j + 1] - 1 && i == 1) b[i][j] = 1;
      }
      if (j > 0) {
        b[i][j] += b[i][j - 1];
      }
      if (j > 1) {
        if (s[j] == s[j + 1] - 1) b[i][j] += b[i - 1][j - 2];
      }
      if (b[i][j] >= MOD) b[i][j] -= MOD;
    }
  }
  int sr = r.size();
  int second = s.size();
  for (int i = 0; i <= sr / 2; i++) {
    for (int j = 0; j <= second / 2; j++) {
      int ur = sr - 2 * i;
      int us = second - 2 * j;
      long long mno1, mno2;
      if (sr == 1 && i == 0)
        mno1 = 1;
      else if (sr == 1 && i > 0)
        mno1 = 0;
      else
        mno1 = a[i][sr - 2];
      if (second == 1 && j == 0)
        mno2 = 1;
      else if (second == 1 && j > 0)
        mno2 = 0;
      else
        mno2 = b[j][second - 2];
      long long dod = 1;
      dod *= povrh(i, us) * mno1;
      dod %= MOD;
      dod *= povrh(j, ur);
      dod %= MOD;
      dod *= mno2;
      dod %= MOD;
      res += dod;
      if (res >= MOD) res -= MOD;
    }
  }
  printf("%lld", res);
  return 0;
}
