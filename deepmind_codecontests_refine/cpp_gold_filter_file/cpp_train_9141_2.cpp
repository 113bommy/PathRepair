#include<bits/stdc++.h>
using namespace std;
const int N=1<<19;
int n,a[N],id[N][2];
bool cmp(int x, int y){
    return a[x]<a[y];
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<(1<<n);i++)
        scanf("%d",&a[i]);
    a[(1<<n)]=-1;
    id[0][0]=0,id[0][1]=(1<<n);
    for (int i=1;i<(1<<n);i++){
        id[i][0]=i,id[i][1]=(1<<n);int x[4];
        for (int j=0;j<n;j++)if (i&(1<<j)){int _i=i^(1<<j);x[0]=id[i][0],x[1]=id[i][1],x[2]=id[_i][0],x[3]=id[_i][1];sort(x,x+4,cmp);id[i][0]=x[3],id[i][1]=x[2]==x[3]?x[1]:x[2];}
    }
    int mx=0;
    for (int i=1;i<(1<<n);i++){
        mx=max(mx,a[id[i][0]]+a[id[i][1]]);
        printf("%d\n",mx);
    }
    return 0;
}