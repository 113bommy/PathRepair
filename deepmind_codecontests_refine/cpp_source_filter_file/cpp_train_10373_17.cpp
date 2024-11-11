#include <bits/stdc++.h>
using namespace std;
int m, n, nums[1010][35], P[1010] = {0}, nCr[1010][1010], basis[1010][35],
                          sz = 0, pivots[1010];
char buf[1010];
int main() {
  int mask = 0x1F, shift = 5;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    for (int j = 0; j < m; j++) {
      nums[i][j >> shift] |= (buf[j] == '1') << (j & mask);
    }
  }
  nCr[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    nCr[i][0] = nCr[i][i] = 1;
    for (int j = 1; j < i; j++) {
      nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % 1000000007;
    }
  }
  P[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= i; j++) {
      P[i] = (P[i] + 1LL * nCr[i - 1][j - 1] * P[i - j]) % 1000000007;
    }
  }
  for (int i = 0; i < m >> shift; i++) nums[n][i] = 0xFFFF;
  nums[n][m >> shift] = (1 << (m & mask)) - 1;
  for (int i = 0; i < m; i++) pivots[i] = -1;
  for (int i = 0; i < m; i++) {
    int idx = 0;
    while (idx <= n && ((nums[idx][i >> shift] >> (i & mask)) & 1) == 0) {
      idx++;
    }
    if (idx == n + 1) continue;
    for (int i = 0; i < 35; i++) {
      basis[sz][i] = nums[idx][i];
    }
    for (int j = idx; j <= n; j++) {
      if ((nums[j][i >> shift] >> (i & mask)) & 1) {
        for (int i = 0; i < 35; i++) {
          nums[j][i] ^= basis[sz][i];
        }
      }
    }
    pivots[i] = sz;
    sz++;
  }
  for (int i = 0; i < m; i++) {
    if (pivots[i] != -1) {
      int u = pivots[i];
      for (int j = 0; j < sz; j++) {
        if (j != u && ((basis[j][i >> shift] >> (i & mask)) & 1))
          for (int z = 0; z < 35; z++) {
            basis[j][z] ^= basis[u][z];
          }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (pivots[i] == -1) {
      int u = -1, v = -1;
      for (int j = 0; j < sz; j++) {
        if ((basis[j][i >> shift] >> (i & mask)) & 1) {
          v = u;
          u = j;
        }
      }
      if (v != -1) {
        for (int z = 0; z < 35; z++) {
          basis[sz][z] = basis[u][z] & basis[v][z];
        }
        for (int j = i + 1; j < m; j++) {
          if (pivots[j] != -1 && ((basis[sz][j >> shift] >> (j & mask)) & 1)) {
            int u = pivots[j];
            for (int k = 0; k < 35; k++) basis[sz][k] ^= basis[u][k];
          }
        }
        for (int j = 0; j < sz; j++) {
          if (basis[j][i >> shift] >> (i & mask) & 1) {
            for (int k = 0; k < 35; k++) {
              basis[j][k] ^= basis[sz][k];
            }
          }
        }
        pivots[i] = sz;
        sz++;
      }
    }
  }
  int ans = 1, num_ones = 0;
  for (int i = 0; i < sz; i++) {
    int no = 0;
    for (int j = 0; j < m; j++) {
      no += (basis[i][j >> shift] >> (j & mask)) & 1;
    }
    num_ones += no;
    ans = 1LL * ans * P[no] % 1000000007;
  }
  ans = 1LL * ans * P[m - num_ones] % 1000000007;
  printf("%d\n", ans);
}
