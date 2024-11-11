#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
    ll n,m;
    string s,t;
    cin>>n>>m>>s>>t;
    ll g=gcd(n,m);
    for(ll i=0;i<g;i++)if(s[i*n/g]!=t[i*m/g]){
        cout<<-1;
        return 0;
    }
    cout<<n*m/g;
}
