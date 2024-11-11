#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll e(ll s,ll p,ll x){
    if(x==0)return 0;
    if(s==1)return 1;
    if(x<=s/2)return eat((s-3)/2,(p-1)/2,x-1);
    else return p/2+1+eat((s-3)/2,(p-1)/2,x-s/2-1);
}
int main(){
    ll n,x,s=1,p=1;cin>>n>>x;
    for(int i=0;i<n;i++){
        s=s*2+3; p=p*2+1;
    }
    cout<<e(s,p,x)<<endl;
}