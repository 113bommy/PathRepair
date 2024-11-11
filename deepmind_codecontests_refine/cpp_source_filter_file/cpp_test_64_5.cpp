#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int K = 4;
const int mods[K] = {998244353, 1000000007, 1000000009, 12344321};
char s[N], str[N];
long long pows[N][K];
long long ha[N][K];
long long haa[N][K];
void get_hash_val(int x, int y, long long a[K]) {
  int l = y - x + 1;
  for (int i = 0; i < K; i++) {
    a[i] = (ha[y][i] - ha[x - 1][i] * pows[l][i]) % mods[i];
    if (a[i] < 0) a[i] += mods[i];
  }
}
void get_hash2_val(int x, int y, long long a[K]) {
  int l = y - x + 1;
  for (int i = 0; i < K; i++) {
    a[i] = (haa[y][i] - haa[x - 1][i] * pows[l][i]) % mods[i];
    if (a[i] < 0) a[i] += mods[i];
  }
}
int get_lcp(int pos, int m) {
  int ans = 0;
  int lt = 1, rt = m, mid;
  while (lt <= rt) {
    mid = (lt + rt) >> 1;
    long long x[K], y[K];
    get_hash_val(pos, pos + mid - 1, x);
    get_hash2_val(1, mid, y);
    bool flag = true;
    for (int k = 0; k < K; k++)
      if (x[k] != y[k]) {
        flag = false;
        break;
      }
    if (flag)
      ans = mid, lt = mid + 1;
    else
      rt = mid - 1;
  }
  return ans;
}
bool check_eq(long long x[], long long y[], long long z[]) {
  for (int k = 0; k < K; k++) {
    if ((x[k] + y[k]) % mods[k] != z[k]) return false;
  }
  return true;
}
int main() {
  for (int k = 0; k < K; k++) pows[0][k] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < K; j++) pows[i][j] = 10 * pows[i - 1][j] % mods[j];
  scanf("%s", s + 1);
  scanf("%s", str + 1);
  int n = strlen(s + 1), m = strlen(str + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < K; j++) {
      ha[i][j] = (ha[i - 1][j] * 10 + s[i] - '0') % mods[j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < K; j++) {
      haa[i][j] = (haa[i - 1][j] * 10 + str[i] - '0') % mods[j];
    }
  }
  for (int i = 1; i + 2 * (m - 1) - 1 <= n; i++) {
    long long x[K], y[K];
    get_hash_val(i, i + m - 2, x);
    get_hash_val(i + m - 1, i + 2 * (m - 1) - 1, y);
    bool flag = true;
    for (int j = 0; j < K; j++) {
      if ((x[j] + y[j]) % mods[j] != haa[m][j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      printf("%d %d\n", i, i + m - 2);
      printf("%d %d\n", i + m - 1, i + 2 * (m - 1) - 1);
      return 0;
    }
  }
  for (int i = 1; i + m - 1 <= n; i++) {
    int prefix = get_lcp(i, m);
    long long x[K], y[K];
    get_hash_val(i, i + m - 1, x);
    if (prefix < m) {
      int l2 = m - prefix;
      if (i + m + l2 - 1 <= n) {
        get_hash_val(i + m, i + m + l2 - 1, y);
        if (check_eq(x, y, haa[m])) {
          printf("%d %d\n", i, i + m - 1);
          printf("%d %d\n", i + m, i + m + l2 - 1);
          return 0;
        }
      }
      if (i > l2) {
        get_hash_val(i - l2, i - 1, y);
        if (check_eq(x, y, haa[m])) {
          printf("%d %d\n", i - l2, i - 1);
          printf("%d %d\n", i, i + m - 1);
          return 0;
        }
      }
    }
    if (m - prefix - 1 > 0) {
      int l2 = m - prefix - 1;
      if (i + m + l2 - 1 <= n) {
        get_hash_val(i + m, i + m + l2 - 1, y);
        if (check_eq(x, y, haa[m])) {
          printf("%d %d\n", i, i + m - 1);
          printf("%d %d\n", i + m, i + m + l2 - 1);
          return 0;
        }
      }
      if (i > l2) {
        get_hash_val(i - l2, i - 1, y);
        if (check_eq(x, y, haa[m])) {
          printf("%d %d\n", i - l2, i - 1);
          printf("%d %d\n", i, i + m - 1);
          return 0;
        }
      }
    }
  }
  return 0;
}
