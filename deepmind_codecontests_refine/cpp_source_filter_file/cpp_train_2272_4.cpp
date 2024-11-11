#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const int INF=1000000000;

int main(){
  int N, C;
  cin >> N >> C;
  int D[35][35], c[510][510];
  rep(i,C){
    rep(j,C) cin >> D[i][j];
  }
  rep(i,N){
    rep(j,N) cin >> c[i][j];
  }
  int sum[3][35]={0};
  rep(col,C){
    rep(i,N){
      rep(j,N){
        int k=(i+j)%3;
        sum[k][col]+=D[c[i][j]-1][col];
      }
    }
  }
  int ans=INF;
  rep(i,C){
    rep(j,C){
      if(j==i) continue;
      rep(k,C){
        if(k==i||k==j) continue;
        int res+=sum[0][i]+sum[1][j]+sum[2][k];
        ans=min(ans,res);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
