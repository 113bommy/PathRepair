w//41
#include<iostream>

using namespace std;

int n;

int d(int p,int i){
  int j=i*2;
  return (p%2)?j/10+j%10:i;
}

int main(){
  char ID[100001];
  int m;
  int a[10];
  cin>>n>>ID>>m;
  for(int i=0;i<m;i++){
    cin>>a[i];
  }
  static int dp[100001][10];
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      if(ID[n-1-i]!='*'){
	dp[i+1][(j+d(i,ID[n-1-i]-'0'))%10]+=dp[i][j];
      }else{
	for(int k=0;k<m;k++){
	  dp[i+1][(j+d(i,a[k]))%10]+=dp[i][j];
	}
      }
    }
  }
  cout<<dp[n][0]<<endl;
  return 0;
}
      