#include <bits/stdc++.h>
using namespace std;
bool exitInput = false;
int ntest = 1, itest = 1;
const char* directions[4] = {"NE", "SE", "SW", "NW"};
const long long Mod = 3210121;
const int maxn = 100000 + 5;
const int maxv = 300000 + 5;
const int maxe = 600000 + 5;
const int root = 1;
char s[maxn + 1001], str[maxn], p[1001];
int n, m, N, Z[maxn + 1001], min_prefix_idx[1001], max_suffix_idx[1001];
void reverse(char* str, int Len) {
  int i, j;
  for (i = 0, j = Len - 1; i < j; ++i, --j) {
    swap(str[i], str[j]);
  }
}
void compute_Z() {
  int i, j, k, L, R;
  Z[0] = N;
  for (k = 0; 1 + k < N && s[k] == s[1 + k]; ++k)
    ;
  Z[1] = k;
  L = 1;
  R = k;
  for (i = 2; i < N; ++i) {
    if (i > R) {
      for (k = 0; i + k < N && s[k] == s[i + k]; ++k)
        ;
      Z[i] = k;
      L = i;
      R = i + k - 1;
    } else {
      j = i - L;
      if (Z[j] >= R - i + 1) {
        for (k = R - i + 1; i + k < N && s[k] == s[i + k]; ++k)
          ;
        Z[i] = k;
        L = i;
        R = i + k - 1;
      } else {
        Z[i] = Z[j];
      }
    }
  }
}
void compute_min_prefix_idx() {
  int i, j, k;
  int max_prefix_len = 0;
  min_prefix_idx[0] = 0;
  for (i = 1; i <= m; ++i) min_prefix_idx[i] = 1e9 + 1;
  for (i = m; i < N; ++i) {
    if (Z[i] > max_prefix_len) {
      for (j = max_prefix_len + 1; j <= Z[i]; ++j) {
        min_prefix_idx[j] = i - m;
      }
      max_prefix_len = Z[i];
    }
  }
}
void compute_max_suffix_idx() {
  int i, j, k;
  int max_suffix_len = 0;
  max_suffix_idx[0] = n;
  for (i = 1; i <= m; ++i) max_suffix_idx[i] = -1;
  for (i = m; i < N; ++i) {
    if (Z[i] > max_suffix_len) {
      for (j = max_suffix_len + 1; j <= Z[i]; ++j) {
        max_suffix_idx[j] = n - 1 - (i - m) - j + 1;
      }
      max_suffix_len = Z[i];
    }
  }
}
int main() {
  int i, j, k;
  int res = 0;
  scanf("%s", str);
  n = strlen(str);
  scanf("%d", &ntest);
  for (itest = 1; itest <= ntest; ++itest) {
    scanf("%s", p);
    m = strlen(p);
    N = n + m;
    s[N] = 0;
    for (i = 0; i < m; ++i) {
      s[i] = p[i];
    }
    for (i = 0; i < n; ++i) {
      s[m + i] = str[i];
    }
    compute_Z();
    compute_min_prefix_idx();
    reverse(str, n);
    reverse(p, m);
    for (i = 0; i < m; ++i) {
      s[i] = p[i];
    }
    for (i = 0; i < n; ++i) {
      s[m + i] = str[i];
    }
    compute_Z();
    compute_max_suffix_idx();
    for (i = 1; i <= m; ++i) {
      j = m - i;
      if (j > 0 && min_prefix_idx[i] + i - 1 < max_suffix_idx[j]) {
        ++res;
        break;
      }
    }
    reverse(str, n);
  }
  printf("%d\n", res);
  return 0;
}
