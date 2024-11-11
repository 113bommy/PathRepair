include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, K, L, S[30010];
long long D[4010][2010], Mod = 1000000007, Res;
int main(){
    scanf("%d%d%d",&n,&m,&K);
    if(n>m)swap(n,m);
    L = (n+m-1)/(K-1);
    int i, j;
    for(i=0;i<=n;i++)D[0][i] = 1;
    for(i=1;i<=L;i++){
        for(j=0;j<=n;j++){
            D[i][j] = D[i-1][j];
            if(j>=K) D[i][j] = (D[i][j]-D[i-1][j-K]+Mod)%Mod;
        }
        for(j=1;j<=n;j++){
            D[i][j] = (D[i][j]+D[i][j-1])%Mod;
        }
    }
    int c = L;
    for(i=n;i>=1;i-=(K-1)){
        Res = (Res + D[c][i])%Mod;
        if(i)Res = (Res - D[c][i-1] + Mod)%Mod;
       // Res = (Res + Mod - S[i])%Mod;
        c--;
    }
    printf("%lld\n",Res);
}