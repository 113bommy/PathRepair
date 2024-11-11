#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main()
{
    int H,W,k,ans=0;
    cin>>H>>W>>k;
    vector<string> c(H);
    rep(i,H) cin>>c[i];
    rep(bith,1<<H) rep(bitw,1<<W)
    {
        int count=0;
        rep(h,H) rep(w,W)
        {
            if(bith>>h&1) continue;
            if(bitw>>w&1) continue;
            if(c[h][w]=='#') count++;
        }
        if(count==k) ans++;
    }
    cout<<ans;
}