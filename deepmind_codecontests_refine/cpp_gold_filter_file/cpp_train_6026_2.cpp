#include <iostream>
using namespace std;
  
int main(){
    int cost[22][22]={0};
    int n,m,i,j,k,a,b,c,d;
    char cc;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cost[i][j] = 1<<28;
        }
    }
    for(i=0;i<m;i++){
        cin>>a>>cc>>b>>cc>>c>>cc>>d;
        cost[a][b]=c;cost[b][a]=d;
    }
    for(k=1;k<=n;k++){
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    cin>>a>>cc>>b>>cc>>c>>cc>>d;
    }
    cout << c-d-cost[a][b]-cost[b][a] << endl;
}