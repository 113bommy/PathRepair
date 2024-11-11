#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
int solve();
int main() {
  srand(0);
  return solve();
}
const int N = 41;
const int MSK = 1 << (N / 2 + 1);
int d[N][N], isclique[2][MSK], dp[MSK];
int bit(int msk, int i) { return (msk >> i) & 1; }
int count(int msk) {
  int res = 0;
  while (msk) {
    res += (msk & 1);
    msk >>= 1;
  }
  return res;
}
void build(int sz, int delta, int *is) {
  for (int msk = 1; msk < (1 << sz); msk++) {
    is[msk] = true;
    for (int i = 0; i < (int)sz; i++) {
      if (bit(msk, i)) {
        int nmsk = msk ^ (1 << i);
        for (int j = 0; j < (int)sz; j++) {
          if (bit(nmsk, j)) {
            if (!d[i + delta][j + delta]) is[msk] = false;
          }
        }
      }
    }
  }
}
int solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) {
      cin >> d[i][j];
    }
  }
  int sz1 = n / 2, sz2 = n - sz1;
  build(sz1, 0, isclique[0]);
  build(sz2, sz1, isclique[1]);
  int maxim = 0;
  for (int msk = 1; msk < (1 << sz1); msk++) {
    if (isclique[msk]) {
      dp[msk] = count(msk);
      uax(maxim, dp[msk]);
      continue;
    }
    for (int i = 0; i < (int)sz1; i++) {
      if (bit(msk, i)) {
        uax(dp[msk], dp[msk ^ (1 << i)]);
      }
    }
  }
  for (int msk = 1; msk < (1 << sz2); msk++) {
    if (isclique[1][msk]) {
      int neighbours = (1 << sz1) - 1;
      for (int i = 0; i < (int)sz2; i++) {
        if (bit(msk, i)) {
          int curmsk = 0;
          for (int j = 0; j < (int)sz1; j++) {
            if (d[i + sz1][j]) {
              curmsk |= (1 << j);
            }
          }
          neighbours &= curmsk;
        }
      }
      uax(maxim, count(msk) + dp[neighbours]);
    }
  }
  double answer = 1.0 * k * k * (maxim - 1) / maxim / 2;
  printf("%.10f", answer);
  return 0;
}
