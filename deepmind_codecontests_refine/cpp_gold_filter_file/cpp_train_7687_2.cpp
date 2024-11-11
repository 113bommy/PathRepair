#include<bits/stdc++.h>
using namespace std;
int m[9][9];
int vis[9];
int sum,n;
void dfs(int cot,int num){
    if(num==n){
        sum++;
        return;
    }
    for(int i=2;i<10;i++){
        if(m[cot][i]==1&&vis[i]==0){
            vis[i]=1;
            dfs(i,num+1);
            vis[i]=0;
        }
    }
}
int main(){
    int mm,a,b;
    cin>>n>>mm;
    for(int i = 0;i<mm;i++){
        cin>>a>>b;
        m[a][b]=1;
        m[b][a]=1;
    }
    sum = 0;
    vis[1]=1;
    dfs(1,1);
    cout<<sum;
    return 0;
}