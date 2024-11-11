#include <bits/stdc++.h>
using namespace std;

int b[2001], w[2001];
int cb[2001][2001], cw[2001][2001], f[2001][2001];

int main(){
  memset(cb, 0, sizeof(cb));
  memset(cw, 0, sizeof(cb));
  memset(f, 0, sizeof(f));
  
  int N;cin>>N;
  for (int i=1;i<=2*N;++i){
    char c;cin>>c;int a;cin>>a;
    if(c=='W') w[a]=i;
    else b[a]=i;
  }

  for (int i=1;i<=N;++i){
    for (int j=1;j<i;++j){
      cb[i][0]+=(b[j]>b[i]);
    }

    for (int j=1;j<=N;++j){
      cb[i][j]=cb[i][j-1]+(b[i]<w[j]);
    }
  }

  for (int i=1;i<=N;++i){
    for (int j=1;j<i;++j){
      cw[0][i]+=(w[j]>w[i]);
    }

    for (int j=1;j<=N;++j){
      cw[j][i]=cw[j-1][i]+(w[i]<b[j]);
    }
  }

  for (int i=1;i<=N;++i){
    f[0][i]=f[0][i-1]+cw[i];
    f[i][0]=f[i-1][0]+cb[i];
  }

  for (int i=1;i<=N;++i){
    for (int j=1;j<=N;++j){
      f[i][j]=min(f[i-1][j]+cb[i][j],f[i][j-1]+cw[i][j]);
    }
  }
  cout << f[N][N] << endl;
  return 0;
}