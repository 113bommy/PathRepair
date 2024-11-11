#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    ll h,w;cin>>h>>w;
    if(h%3==0 || w%3==0){
        cout<<0<<endl;
    }
    else{
        ll ans = h*w;
        rep(i,h-1){
            ll ws=w/2;
            ll tmp=max((h-i-1)*w-abs(i+1)*ws,abs((h-i-1)*w-(i+1)*(w-ws)));
            ans=min(tmp,ans);
        }
        rep(i,w){
            ll hs=h/2;
            ll tmp=max((w-i-1)*h-abs(i+1)*hs,abs((w-i-1)*h-(i+1)*(h-hs)));
            ans=min(tmp,ans);            
        }
        ans=min(ans,h);
        ans=min(ans,w);
        cout<<ans<<endl;
    }
	return 0;
}