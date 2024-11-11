\#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,a,b,h[100001],t;

int main(void){
    cin>>n>>a>>b;
    ll l=0, r=(ll)1e9,m,sub,tm;
    for(int i=0;i<n;i++){
        cin>>t;
        h[i]=t;
    }
    while(r-l>1){
        m=l+(r-l)/2;
        tm=m;
        for(int i=0;i<n;i++){
            if(h[i]-tm*b<0)continue;
            sub=(h[i]-tm*b)/(a-b);
            if((h[i]-tm*b)%(a-b))m-=sub+1;
            else m-=sub;
        }
        if(m<0)l=tm;
        else r=tm;
    }
    cout<<r<<endl;
    return 0;
}
