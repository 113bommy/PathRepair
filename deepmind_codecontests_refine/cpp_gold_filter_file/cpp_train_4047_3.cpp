#include <bits/stdc++.h>
using namespace std;
int main(){
    long long ans=0,a,cnt=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a)cnt+=a;
        else{
            ans+=cnt/2;
            cnt=0;
        }
    }
    cout<<ans+(cnt/2)<<endl;
    return 0;
}
