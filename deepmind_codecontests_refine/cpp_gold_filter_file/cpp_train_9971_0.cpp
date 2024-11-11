#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    rep(0,i,n)cin>>a[i]>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n%2==1){
        cout<<b[(n-1)/2]-a[(n-1)/2]+1;
    }else{
        cout<<b[(n-1)/2]+b[(n-1)/2+1]-(a[(n-1)/2]+a[(n-1)/2+1])+1;
    }
    
}
