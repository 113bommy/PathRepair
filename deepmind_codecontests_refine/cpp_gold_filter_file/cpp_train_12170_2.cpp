#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int GCD(int a,int b){
    if(b>a)swap(a,b);
    return (b==0)?a:GCD(b,a%b);
}
int LCM(int a,int b){
    return a/GCD(a,b)*b;
}
int l[101],r[101],w1[101],w2[101];
int memo[101];
int dfs(int x){
    if(x==0)return 1;
    if(memo[x]!=-1)return memo[x];
    int red=l[x]*dfs(w1[x]);
    int blue=r[x]*dfs(w2[x]);
    int lcm=LCM(red,blue);
    return memo[x]=lcm/l[x]+lcm/r[x];
}
int main(){
    int n;
    while(scanf("%d",&n),n){
        bool flag[101];fill(flag,flag+n+1,true);
        fill(memo,memo+n+1,-1);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&l[i],&r[i],&w1[i],&w2[i]);
            flag[w1[i]]=flag[w2[i]]=false;
        }
        for(int i=1;i<=n;i++){
            if(flag[i]){
                printf("%d\n",dfs(i));
                break;
            }
        }
    }
    return 0;
}