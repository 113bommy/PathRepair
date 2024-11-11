#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef __int128 ll;
const ll mod=1000000007;
const ll BIG=1e15;

int main(){
    ll T1,T2,A1,A2,B1,B2;
    cin>>T1>>T2>>A1>>A2>>B1>>B2;
    ll S=T1*(A1-B1)+T2*(A2-B2);
    ll C=T1*(A1-B1);
    if(S==0) cout<<"infinity"<<endl;
    else if(S>0 && C>0) cout<<0<<endl;
    else if(S<0 && C<0) cout<<0<<endl;
    else{
        C=abs(C);
        S=abs(S);
        ll ans=C/S;
        ans*=2;
        if((C%S)>0) ans++;
        cout<<ans<<endl;
    }

}