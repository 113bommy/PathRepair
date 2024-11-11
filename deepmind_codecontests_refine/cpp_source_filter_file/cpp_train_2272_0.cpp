#include<iostream>

#define rep(i,n) for(int i = 0; i < n; ++i)

int N, C, X;
int D[30][30];
int t[3][30];

int main() {
  scanf("%d %d", &N, &C);
  rep(i,C) rep(j,C) scanf("%d", &D[i][j]);
  rep(i,N) rep(j,N) scanf("%d", &X), ++t[(i+j)%3][X-1];
  
  int res = 1 << 30;
  rep(i,C) rep(j, C) if(i!=j) rep(k,C) if(i!=k && j!=k) {
    int tt = 0;
    rep(l,C) tt += D[l][i]*t[0][l];
    rep(l,C) tt += D[l][j]*t[1][l];
    rep(l,C) tt += D[l][k]*t[2][l];
    if (tt < res) res = tt;
  }
  pritnf("%d\n", res);
  return 0;
}