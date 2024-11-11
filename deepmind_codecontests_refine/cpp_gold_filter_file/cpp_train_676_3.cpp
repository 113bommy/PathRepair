#include <bits/stdc++.h>
using namespace std;
int N, M, K;
vector<vector<vector<char> > > G;
int main() {
  scanf("%d %d %d", &N, &M, &K);
  G.resize(N);
  for (int i = 0; i < N; i++) {
    G[i] = vector<vector<char> >(M, vector<char>(K));
    for (int j = 0; j < M; j++) {
      scanf("\n");
      for (int k = 0; k < K; k++) {
        scanf("%c", &G[i][j][k]);
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 0; k < K; k++) {
        if (G[i][j][k] == '0') continue;
        if (i > 0) {
          if (G[i - 1][j][k] == '1') {
            if (i < N - 1 && G[i + 1][j][k] == '1') {
              cnt++;
              continue;
            }
            if (j < M - 1 && G[i][j + 1][k] == '1') {
              if (G[i - 1][j + 1][k] == '0') {
                cnt++;
                continue;
              }
            }
            if (k < K - 1 && G[i][j][k + 1] == '1') {
              if (G[i - 1][j][k + 1] == '0') {
                cnt++;
                continue;
              }
            }
          }
        }
        if (j > 0) {
          if (G[i][j - 1][k] == '1') {
            if (j < M - 1 && G[i][j + 1][k] == '1') {
              cnt++;
              continue;
            }
            if (i < N - 1 && G[i + 1][j][k] == '1') {
              if (G[i + 1][j - 1][k] == '0') {
                cnt++;
                continue;
              }
            }
            if (k < K - 1 && G[i][j][k + 1] == '1') {
              if (G[i][j - 1][k + 1] == '0') {
                cnt++;
                continue;
              }
            }
          }
        }
        if (k > 0 && G[i][j][k - 1] == '1') {
          if (k < K - 1 && G[i][j][k + 1] == '1') {
            cnt++;
            continue;
          }
          if (i < N - 1 && G[i + 1][j][k] == '1') {
            if (G[i + 1][j][k - 1] == '0') {
              cnt++;
              continue;
            }
          }
          if (j < M - 1 && G[i][j + 1][k] == '1') {
            if (G[i][j + 1][k - 1] == '0') {
              cnt++;
              continue;
            }
          }
        }
      }
    }
  }
  printf("%d", cnt);
}
