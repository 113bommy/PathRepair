#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
int main(void){
    ll n,a;
    cin>>n;
    vector<ll> v;
    rep(i,0,n){
        cin>>a;
        if(a<3200)v.at(a/400)=1;
        else v.at(8)++;
    }
    rep(i,1,8)v.at(0)+=v.at(i);
    cout<<max(v.at(0),(ll)1)<<' '<<min(v.at(0)+v.at(8))<<endl;
}