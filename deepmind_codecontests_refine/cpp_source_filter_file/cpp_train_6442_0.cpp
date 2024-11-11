#include <iostream>
#include <cstdio>
using namespace std;

double memo [101][102];
double mp[101][101];
double ans;
int n,m;
int cnt;

void saiki(double seki,double pseki,int mae,int kai) {
  //  cout <<"seki="<<seki<<" mae="<<mae<<" kai="<<kai<<endl;
  cnt++;
  
  if(kai == m && ans < seki) ans = seki;
  if(kai == m && mae != -1) memo[kai][mae] = 1;
  
  if(kai < m) {
    for(int i=1;i<=n;i++) {
      if(memo[kai+1][i] == -1) {
	saiki(seki*mp[mae][i],seki,i,kai+1);
	if(memo[kai][mae] < memo[kai+1][i]*mp[mae][i]) memo[kai][mae] = memo[kai+1][i]*mp[mae][i];
      }
      else {
	if(memo[kai][mae] < memo[kai+1][i]*mp[mae][i])memo[kai][mae] = memo[kai+1][i]*mp[mae][i];
	saiki(memo[kai][mae]*seki,-1,-1,m);
      }
    }
  }
}

int main(){
  
  while(1){
    cin >> n>> m;
    if(n == 0 && m == 0) break;
    
    for(int i=0;i<=n;i++)
      for(int j=0;j<=n;j++)
	if(i == 0 || j == 0) mp[i][j] = 1;
	else cin >> mp[i][j];

    
    for(int i=0;i<=m;i++)
      for(int j=0;j<=n;j++)
	memo[i][j] = -1;

    ans = 0;
    
    int ans2=0;
    for(int i=1;i<=n;i++) {
      saiki(1,1,i,1);
      for(int j=0;j<=n;j++){
	if(ans2 < memo[1][i]) ans2 = memo[1][i];
	memo[1][i] = memo[2][i]= -1;
      }
     ?\?\ for(int j=0;j<=m;j++)for(int k=0;k<=n;k++)memo[j][k] = -1;
    } 
    

    
    //    cout << ans2 << endl;
    printf("%.2f\n",ans);
    //cout << cnt << endl;
  }

  return 0;
}