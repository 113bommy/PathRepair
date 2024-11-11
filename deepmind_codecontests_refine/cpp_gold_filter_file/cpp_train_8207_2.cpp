#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
int main(void){
    ll n;cin>>n;
    if(n%11>0&&n%11<=6)cout<<n/11*2+1<<endl;
    else cout<<(n+10)/11*2;
}