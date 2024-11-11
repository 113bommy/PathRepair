#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 * 2 + 100, mod = 1000 * 1000 * 1000 + 7;
long long n, m = 7;
long long ans[8][130], dp[8][25][130][130], num_h[10];
void merge1(int h, int l) {
  for (int mmask = 0; mmask < (1 << h); mmask++) {
    for (int lmask = 0; lmask < (1 << h); lmask++) {
      for (int rmask = 0; rmask < (1 << h); rmask++) {
        dp[h][l][lmask][rmask] =
            (dp[h][l][lmask][rmask] +
             dp[h][l - 1][lmask][mmask] * dp[h][l - 1][mmask][rmask]) %
            mod;
      }
    }
  }
}
void merge2(int h, int l, bool b) {
  if (b == 0) {
    for (int lmask = 0; lmask < (1 << h); lmask++) {
      for (int rmask = 0; rmask < (1 << h); rmask++) {
        dp[h][20][lmask][rmask] = dp[h][l][lmask][rmask];
      }
    }
    return;
  }
  for (int mmask = 0; mmask < (1 << h); mmask++) {
    for (int lmask = 0; lmask < (1 << h); lmask++) {
      for (int rmask = 0; rmask < (1 << h); rmask++) {
        dp[h][21][lmask][rmask] =
            (dp[h][21][lmask][rmask] +
             dp[h][20][lmask][mmask] * dp[h][l][mmask][rmask]) %
            mod;
      }
    }
  }
  for (int lmask = 0; lmask < (1 << h); lmask++) {
    for (int rmask = 0; rmask < (1 << h); rmask++) {
      dp[h][20][lmask][rmask] = dp[h][21][lmask][rmask];
      dp[h][21][lmask][rmask] = 0;
    }
  }
}
void init(int h) {
  for (int lmask = 0; lmask < (1 << h); lmask++) {
    for (int rmask = 0; rmask < (1 << h); rmask++) {
      dp[h][20][lmask][rmask] = 1;
    }
  }
  for (int mmask = 0; mmask < (1 << (h - 1)); mmask++) {
    int nmask = (mmask | (1 << (h - 1))) * 2 + 1;
    for (int lmask = 0; lmask < (1 << h); lmask++) {
      for (int rmask = 0; rmask < (1 << h); rmask++) {
        bool b = 1;
        for (int i = 0; i < h; i++) {
          if ((rmask & (1 << i)) && (lmask & (1 << i)) &&
              (nmask & (1 << i) && (nmask & (1 << (i + 1)))))
            b = 0;
        }
        if (b) dp[h][0][lmask][rmask]++;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  for (int i = 1; i <= m; i++) cin >> num_h[i];
  for (int h = 1; h <= m; h++) {
    init(h);
    for (int l = 1; l < 10; l++) {
      merge1(h, l);
    }
  }
  for (int h = 1; h <= m; h++) {
    bool b = 0;
    for (int i = 0; i < 20; i++) {
      if (num_h[h] & (1 << i)) {
        merge2(h, i, b);
        b = 1;
      }
    }
  }
  bool f = 1;
  int oh;
  for (int h = 1; h <= m; h++) {
    if (!num_h[h]) continue;
    if (f) {
      f = 0;
      for (int rmask = 0; rmask < (1 << h); rmask++) {
        ans[h][rmask] = (ans[h][rmask] + dp[h][20][(1 << h) - 1][rmask]);
      }
      oh = h;
      continue;
    }
    int maskor = (1 << h) - (1 << oh);
    for (int mmask = 0; mmask < (1 << oh); mmask++) {
      for (int rmask = 0; rmask < (1 << (h)); rmask++) {
        ans[h][rmask] = (ans[h][rmask] +
                         ans[oh][mmask] * dp[h][20][mmask | maskor][rmask]) %
                        mod;
      }
    }
    oh = h;
  }
  cout << ans[oh][(1 << oh) - 1] << endl;
}
