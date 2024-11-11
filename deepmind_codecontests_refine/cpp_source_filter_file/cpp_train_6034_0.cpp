#include<iostream>
using namespace std;
int p1[9],p2[9];

#define rep(i,n) for(int i=0;i<(int)n;i++)
double ans = 0;
long long dp[9][(1 << 9)][200]={0};

void solve(){
  rep(i,9)rep(j,(1<<9)rep(k,200)dp[i][j][k]=0;
  rep(j,9){
    int state = ( 1 << j);
    if ( p1[0]>p2[j]){
      dp[0][state][p1[0]+p2[j]]+=1;
    }else {
      dp[0][state][0]+=1;
    }      
  }
  
  for(int i=0;i<8;i++){
    rep(j,(1<<9)){
      rep(k,200){
	if ( dp[i][j][k] == 0)continue;
	rep(l,9){
	  if ( ( (1 << l)&j) != 0)continue;
	  if (p1[i+1]>p2[l]){
	    dp[i+1][(1<<l)|j][k+p1[i+1]+p2[l]]+=dp[i][j][k];
	  }else {
	    dp[i+1][(1<<l)|j][k]+=dp[i][j][k];
	  }
	}
      }
    }
  }
  

  double div=0;
  rep(i,200)div+=dp[8][(1 << 9)-1][i];
  for(int i=86;i<200;i++){
    ans+=dp[8][(1<<9)-1][i];
  }
  //cout << ans << " " << div << endl;

  ans/=div;
  
}


main(){
  int te;
  cin>>te;
  while(te--){
    ans =0;
    rep(i,9)cin>>p1[i];
    rep(i,9)cin>>p2[i];
    solve();
    
    printf("%.5lf %.5lf\n",ans,1-ans);
  }
}