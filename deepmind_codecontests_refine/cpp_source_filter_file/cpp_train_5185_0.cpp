#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
int main(){
    int n,d;
    cin >>n>>d;
    vector<vector<int>>x(x,vector<int>(d))
    rep(i,d){
        rep(j,d) cin>>x[i][j];
    }
int ans=0;
rep(i,n)rep(j,i){
    int sq=0;
    rep(k,d){
        int s=x[i][k]-x[j][k];
        sq+=s*s;

    }
    int s=sqrt(sq)+0.5;
    if(s*s==sq)ans++;
}
cout<<ans<<endl;
return 0;
}