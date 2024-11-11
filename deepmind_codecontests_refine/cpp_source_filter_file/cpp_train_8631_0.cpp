#include<cstdio>
using namespace std;
  
typedef double D;
  
int n,a[110],r;
D b,v,e,f;
D dp[10100][110];
const D EPS = 1e-8;
  
int main(){
  while(scanf("%d",&n),n){
    a[0] = 0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%lf%d%lf%lf%lf",&b,&r,&v,&e,&f);
  
    for(int i=0;i<=a[n];i++)
      for(int j=0;j<=n;j++)dp[i][j] = 1e15;
    dp[0][0] = 0;
  
    int pos = 1;
    for(int i=0;i<a[n];i++){
      if(i==a[pos]){
    for(int j=0;j<pos;j++){
      if(dp[i][pos] > dp[i][j] + b + EPS){
        dp[i][pos] = dp[i][j] + b;
      }
    }
    pos++;
      }
  
      for(int j=0;j<=n;j++){
    if(dp[i][j] + ESP >= 1e15)continue;
    int x = i-a[j];
    D cost = (x<r)?(1.0/(v-f*(r-x))):(1.0/(v-e*(x-r)));
    if(dp[i+1][j] > dp[i][j] + cost + EPS){
      dp[i+1][j] = dp[i][j] + cost;
    }
      }
    }
      
    D res = 1e15;
    for(int i=0;i<=n;i++){
      if(res > dp[a[n]][i] + EPS)res = dp[a[n]][i];
    }
    printf("%.10lf\n",res);
  }
}