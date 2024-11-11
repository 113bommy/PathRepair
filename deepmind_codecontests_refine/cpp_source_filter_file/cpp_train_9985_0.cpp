#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;++i)
using namespace std;
int main(){
int u,r,q,a,b,c;
while(cin>>r,r){cin>>r>>r;
vector<int>t(r),m(r),s(r);
r(i,r)cin>>t[i]>>m[i]>>m[i]>>s[i];cin>>q;
r(i,q){cin>>a>>b>>c;
int an=0,cn=0,p=a;
r(i,t.size()){u=min(t[i],b);
if(cnt)an+=max(u-p,0);
if(m[i]==c){if(s[i])cn++;else cn--;}
p=max(p,u);}
cout<<an<<endl;}}}