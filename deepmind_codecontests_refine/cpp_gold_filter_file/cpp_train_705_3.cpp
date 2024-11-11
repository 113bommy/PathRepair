#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>vec(m);
rep(i,m){
int k;cin>>k;
vec[i].resize(k);
rep(j,k){
cin>>vec[i][j];
--vec[i][j];
}
}
vector<int>p(m);
rep(i,m)cin>>p[i];
int ans=0;
for(int i=0;i<(1<<n);++i){
bool ok=true;
rep(j,m){
int c=0;
for(int id:vec[j]){
if((i>>id)&1){++c;}
}
c%=2;
if(c!=p[j]){
ok=false;
}
}
if(ok){++ans;}

}


cout<<ans<<endl;
return 0;
}