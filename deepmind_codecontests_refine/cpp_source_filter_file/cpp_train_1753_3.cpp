#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll k,a,b;
    cin>>k>>a>>b;
    if(a>=k) res = 1;
    else if(a<=b) res = -1;
    else{
        ll x = (k-a)/(a-b);
        res = x*2;
        if(x*(a-b)>=k);
        else if(x*(a-b)+a>=k) res += 1;
        else res += 3;
    }
    cout<<res<<endl;
    return 0;
}
