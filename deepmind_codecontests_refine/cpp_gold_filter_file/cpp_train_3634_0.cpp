#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int C, D, W, X, E[20][40], F[20][40], dp[32][52][8];

void main2() {
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < D; ++i) { // ツ禿コツ付
    for (int j = 0; j <= W; ++j) { // ツ氾ヲツ労ツ度
      for (int k = 0; k <= X; ++k) { // 2ツ嘉アツ暗按湘」ツづ個δ可イツブツづーツ行ツつ、ツ禿コ
        for (int l = 0; l < C; ++l) { // ツ地ツ暗ヲ
          int dW = F[l][i], dE = E[l][i];
          if (dE > 0 && dW + j <= W) {
            dp[i+1][j+dW][k] = max(dp[i+1][j+dW][k],
                                   max(dp[i][j+dW][k], dp[i][j][k] + dE));
            if (k < X) {
              // ツ湘」ツつェツづゥ
              for (int ll = l-1; ll >= 0; --ll) {
                dW += F[ll][i]; dE += E[ll][i];
                if (dW + j > W || E[ll][i] == 0) break;
                dp[i+1][j+dW][k+1] =
                    max(dp[i+1][j+dW][k+1],
                        max(dp[i][j+dW][k+1], dp[i][j][k] + dE));
              }
              // ツ可コツつェツづゥ
              dW = F[l][i], dE = E[l][i]; // ツ渉可甘コツ可サ
              for (int ll = l+1; ll < C; ++ll) {
                dW += F[ll][i]; dE += E[ll][i];
                if (dW + j > W || E[ll][i] == 0) break;
                dp[i+1][j+dW][k+1] =
                    max(dp[i+1][j+dW][k+1],
                        max(dp[i][j+dW][k+1], dp[i][j][k] + dE));
              }
            }
          } else {
            dp[i+1][j+dW][k] = max(dp[i+1][j+dW][k], dp[i][j+dW][k]);
          }
        }
      }
    }
  }
  int ans = -1;
  for (int j = 0; j <= W; ++j) {
    for (int k = 0; k <= X; ++k) {
      // printf("%d,%d => %d\n", j,k,dp[D][j][k]);
      ans = max(ans, dp[D][j][k]);
    }
  }

  printf("%d\n", ans);
}

int main() {
  while (-1 != scanf("%d%d%d%d", &C, &D, &W, &X)) {
    if (!(C)) break;
    rep(i,C) rep(j,D) scanf("%d", E[i]+j);
    rep(i,C) rep(j,D) scanf("%d", F[i]+j);
    main2();
  }
  return 0;
}