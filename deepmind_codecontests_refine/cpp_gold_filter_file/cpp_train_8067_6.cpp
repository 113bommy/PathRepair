#include <bits/stdc++.h>
using namespace std;
int lb(const vector<int> &cor, int n) {
  int L = cor.size();
  if (cor[0] >= n) {
    return 0;
  }
  int bg = L;
  int sm = 0;
  while (bg - sm > 1) {
    int md = (bg + sm) / 2;
    if (cor[md] >= n) {
      bg = md;
    } else {
      sm = md;
    }
  }
  return bg;
}
bool inmax(int &a, int b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
vector<vector<int> > prd(const vector<vector<int> > &a,
                         const vector<vector<int> > &b, int L) {
  vector<vector<int> > trt(L, vector<int>(L, 0));
  for (int i = 0; i < L; i++) {
    for (int j = i; j < L; j++) {
      for (int k = i; k <= j; k++) {
        inmax(trt[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return trt;
}
int clcA(vector<vector<int> > &A, int N, const int L) {
  vector<vector<int> > trt(L, vector<int>(L, 0));
  vector<vector<int> > tmp = A;
  while (N) {
    if (N & 1) {
      trt = prd(trt, tmp, L);
    }
    N /= 2;
    tmp = prd(tmp, tmp, L);
  }
  return trt[0][L - 1];
}
int main() {
  int N, T;
  if (scanf("%d%d", &N, &T) == EOF) {
    return 0;
  }
  vector<int> cor;
  int A[N];
  for (int i = 0; i < N; i++) {
    if (scanf("%d", A + i) == EOF) {
      return 0;
    }
    cor.push_back(A[i]);
  }
  sort(cor.begin(), cor.end());
  cor.erase(unique(cor.begin(), cor.end()), cor.end());
  for (int i = 0; i < N; i++) {
    A[i] = lb(cor, A[i]);
  }
  int L = cor.size();
  int dp2[L][N + 1];
  for (int i = 0; i < L; i++) {
    fill(dp2[i], dp2[i] + N + 1, N + 1);
    dp2[i][0] = i;
    bool f = false;
    for (int j = 0; j < N; j++) {
      if (f) {
        if (A[j] >= i) {
          int bg = N;
          int sm = 0;
          while (bg - sm > 1) {
            int md = (bg + sm) / 2;
            if (dp2[i][md] > A[j]) {
              bg = md;
            } else {
              sm = md;
            }
          }
          dp2[i][bg] = A[j];
        }
      } else {
        if (A[j] == i) {
          f = true;
          dp2[i][1] = i;
        }
      }
    }
  }
  vector<vector<int> > dp(L);
  fill(dp.begin(), dp.end(), vector<int>(L, 0));
  for (int i = 0; i < L; i++) {
    for (int j = 0; j <= N; j++) {
      for (int k = dp2[i][j]; k < L; k++) {
        inmax(dp[i][k], j);
      }
    }
  }
  printf("%d\n", clcA(dp, T, L));
  return 0;
}
