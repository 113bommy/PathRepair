#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll h,w;cin>>h>>w;
    ll ans=1e9;
    for (int i=0;i<2;i++) {
        for (int j=1;j<h;j++) {
            int hh=h-j;
            int hhh=hh/2;
            int hhhh=hh-hhh;
            ll mx=max(j,max(hhh,hhhh));
            ll mn=min(j,min(hhh,hhhh));
            ans=min(ans,mx*w-mn*w);
            ll ww=w/2;
            ll www=w-ww;
            mx=max(j*w,max(ww*hh,www*hh));
            mn=min(j*w,min(ww*hh,www*hh));
            ans=min(ans,mx-mn);
        }
        swap(h,w);
    }
    cout<<ans<<endl;
    return 0;
}