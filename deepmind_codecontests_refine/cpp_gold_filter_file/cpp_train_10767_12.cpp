#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[128][1 << 17];
long long b[128][128];
long long nCr[100200][128];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  nCr[0][0] = 1;
  for (int i = 1; i < (100200); i++) {
    nCr[i][0] = 1;
    for (int j = 1; j < (128); j++) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
      if (nCr[i][j] >= 1000000007LL) nCr[i][j] -= 1000000007LL;
    }
  }
  cin >> n >> m;
  for (int i = 0; i < (n); i++) {
    cin >> a[101][i];
  }
  for (int i = 0; i < (m); i++) {
    int l, r, K;
    cin >> l >> r >> K;
    l--;
    r--;
    int L = r - l;
    for (int j = 0; j < (K + 1); j++) {
      b[0][j] = nCr[L + K - j][K - j];
    }
    for (int j = 1; j < (K + 2); j++) {
      b[j][0] = b[j - 1][0];
      if ((j & 3) == 0) {
        for (int k = 1; k < (K + 2 - j); k++) {
          b[j][k] = (b[j][k - 1] + b[j - 1][k]) % 1000000007LL;
        }
      } else {
        for (int k = 1; k < (K + 2 - j); k++) {
          b[j][k] = b[j][k - 1] + b[j - 1][k];
        }
      }
    }
    a[100 - K][l] += 1;
    for (int j = 0; j < (K + 1); j++) {
      if (j % 2 == 0) {
        a[100 - K][r + 1 + j] +=
            1000000007LL - b[j + 1][K + 1 - (j + 1)] % 1000000007LL;
      } else {
        a[100 - K][r + 1 + j] += b[j + 1][K + 1 - (j + 1)];
      }
    }
  }
  a[0][0] %= 1000000007LL;
  for (int j = 1; j < (n); j++) {
    a[0][j] = (a[0][j] + a[0][j - 1]) % 1000000007LL;
  }
  for (int i = 1; i < (101); i++) {
    if ((i & 1) == 0) {
      a[i][0] = (a[i][0] + a[i - 1][0]) % 1000000007LL;
      for (int j = 1; j < (n); j++) {
        a[i][j] = (a[i][j] + a[i - 1][j] + a[i][j - 1]) % 1000000007LL;
      }
    } else {
      a[i][0] = a[i][0] + a[i - 1][0];
      for (int j = 1; j < (n); j++) {
        a[i][j] = (a[i][j] + a[i - 1][j] + a[i][j - 1]);
      }
    }
  }
  for (int i = 0; i < (n); i++) {
    cout << (a[100][i] + a[101][i]) % 1000000007LL << " ";
  }
}
