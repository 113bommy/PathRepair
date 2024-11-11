#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = (int) 50 + 10;
const int INF = (int) 0x3f3f3f3f;
typedef long long LL;

int M,N,A,B,C,T;
int s[MAXN];

struct Matrix{
    LL a[MAXN][MAXN];
}st,mp;

Matrix Matrix_Multiply(const Matrix& a,const Matrix& b,int MOD){
    Matrix c;
    memset(c.a,0,sizeof(c.a));
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                c.a[i][k]+=a.a[i][j]*b.a[j][k];
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) c.a[i][j]%=MOD;
    }
    return c;
}

void Power(int X,int MOD){
    while(X){
        if(X&1) st=Matrix_Multiply(st,mp,MOD);
        mp=Matrix_Multiply(mp,mp,MOD);
        X>>=1;
    }
}

void work(){
    while(~scanf("%d%d%d%d%d%d",&N,&M,&A,&B,&C,&T)){
        for(int i=1;i<=N;i++) scanf("%d",&s[i]);
        memset(mp.a,0,sizeof(mp.a));
        for(int i=1;i<=N;i++){
            mp.a[i][i-1]=A;
            mp.a[i][i]=B;
            mp.a[i][i+1]=C;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++) st.a[i][j]=(i==j);
        }
        Power(T,M);
        for(int i=1;i<=N;i++){
            LL ans=0;
            for(int j=1;j<=N;j++){
                ans=(ans+st.a[i][j]*s[j])%M;
            }
            printf("%lld%s",ans,i==N ? "\n" : " ");
        }
    }
}

int main(){
#ifdef NNever
    freopen("data.in","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // NNever
    work();
    return 0;
}








