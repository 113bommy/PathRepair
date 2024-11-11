#include<bits/stdc++.h>
using namespace std;
long long k,a,b,ans;
int main(){
    cin>>k>>a>>b;
    if(a>=k){
        cout<<1<<endl;
        return 0;
    }
    if(a<=b){
        cout<<-1<<endl;
        return 0;
    }
    t=int(bool((k-a)%(a-b)));
    ans=((k-a)/(a-b)+t)*2+1;
    cout<<ans<<endl;
    return 0;
}