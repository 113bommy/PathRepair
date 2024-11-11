#include<iostream>
using namespace std;
int main(){
  int dp[1001][1001];
  int n,W;
  int v[1000],w[1000];
  int num=0;
  while(cin>> W,W){
    num++;
    cin>> n;
    for(int i=0;i<w+1;i++){
      dp[0][i]=0;
    }

    for(int i=0;i<n;i++){
      char c;
      cin>> v[i]>> c>> w[i];
    }

    for(int i=1;i<=n;i++){
      for(int j=1;j<=W;j++){
	if(j<w[i-1]){
	  dp[i][j]=dp[i-1][j];
	}else{
	  dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
	}
      }
    }

    int mv=0,mw;
    for(int j=0;j<=W;j++){
      if(mv<dp[n][j]){
	mv=dp[n][j];
	mw=j;
      }
    }
    /*for(int i=0;i<=n;i++){
      for(int j=0;j<=W;j++){
	cout<< dp[i][j];
      }
      cout<< endl<< endl;
    }
    */
    cout<< "Case "<< num<< ":"<< endl;
    cout<< mv<< endl;
    cout<< mw<< endl;
  }
}