h#include <cstdio>

double dp[302][302][302];

int cnt[4];

int main(){
  int N;
  scanf("%d",&N);
  for(int k=0;k<=N;k++){
    for(int j=0;j<=N;j++){
      for(int i=0;i<=N;i++){
	if(i==0&&j==0&&k==0){
	  continue;
	}
	double sum=0;
	if(i>0) sum+=i*dp[i-1][j][k];
	if(j>0) sum+=j*dp[i+1][j-1][k];
	if(k>0) sum+=k*dp[i][j+1][k-1];
	dp[i][j][k]=(sum+N)/(i+j+k);
	//printf("1:%d 2:%d 3:%d %.10lf\n",i,j,k,dp[i][j][k]);
      }
    }
  }
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt[A]++;
  }
  printf("%.10lf\n",dp[cnt[1]][cnt[2]][cnt[3]]);
  return 0;
}
