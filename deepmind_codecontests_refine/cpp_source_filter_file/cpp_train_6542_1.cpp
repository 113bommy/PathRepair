#include<iostream>
using namespace std;
long long n,p,ans=1,a,cnt0,cnt1;
main(){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>a;
        ans*=2;
        if(a%2)cnt1++;
        else cnt0++;
    }
    if(cnt0==n and p==0)cout<<ans<<endl;
    else if(cnt==n and p==1)cout<<0<<endl;
    else cout<<ans/2<<endl;
}