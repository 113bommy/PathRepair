#include<bits/stdc++.h>
using namespace std;
int p,a[3005];
int iC[3005][3005];
int inv[3005],ans;
int xs[3005][3005];
int g[3005];

int main(){
    scanf("%d",&p);
    for(int i=0;i<p;i++) scanf("%d",&a[i]);
    iC[0][0]=1;
    for(int i=1;i<=3000;i++){
        iC[i][0]=iC[i][i]=1;
        for(int j=1;j<i;j++) iC[i][j]=iC[i-1][j-1]+iC[i-1][j],iC[i][j]%=p;
    }
    for(int i=1;i<=3000;i++){
        for(int j=0;j<=i;j++) if((j&1)^(i&1)) iC[i][j]=p-iC[i][j];
    }
    inv[1]=1;
    for(int i=2;i<p;i++) inv[i]=(p-p/i)*inv[p%i]%p;
    inv[0]=1;
    for(int i=1;i<p;i++) inv[i]=inv[i]*inv[i-1]%p;
    for(int i=1;i<p;i++) xs[1][i]=1;
    for(int i=2;i<p;i++){
        for(int j=i;j<p;j++) xs[i][j]=(xs[i-1][j-1]+xs[i][j-1])*i%p;
    }
    for(int i=p-1;i>=1;i--){
        ans=0;
        for(int j=0;j<=i;j++) ans=(ans+iC[i][j]*a[j])%p;
        for(int j=i+1;j<p;j++){
            ans=(ans-xs[i][j]*g[j]%p+p)%p;
        }
        g[i]=ans*inv[i]%p;
    }
    g[0]=a[0];
    for(int i=0;i<p;i++) printf("%d ",g[i]);

    return 0;
}