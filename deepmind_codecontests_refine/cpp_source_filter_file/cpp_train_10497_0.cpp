#include <bits/stdc++.h>
using namespace std;
const int K=3005;
int x[K][K];
int n,k;
int getsize(int x1,int y1,int x2,int y2){
    return x[x2][y2]-x[x2][y1]-x[x1][y2]+x[x1][y1];
}
int main()
{
    cin>>n>>k;
    int a,b;
    char c;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        a%=2*k,b%=2*k;
        if(c=='W')
            b+=k;
        x[a%(2*k)+1][b%(2*k)+1]++;
    }
    for(int i=1;i<=2*k;i++)
        for(int j=1;j<=2*k;j++)
            x[i][j]=x[i][j]+(x[i-1][j]+x[i][j-1]-x[i-1][j-1]);
    int ans=0,sum;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++){
            sum=getsize(0,0,i,j);
            sum+=getsize(i,j,k+i,k+j);
            sum+=getsize(k+i,k+j,2*k,2*k);
            sum+=getsize(k+i,0,2*k,j);
            sum+=getsize(0,k+j,i,2*k);
            sum=max(n-sum,sum);
            ans=max(ans,sum);
        }
    cout<<ans
}