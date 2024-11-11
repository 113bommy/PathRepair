#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
signed main(){
    int m;
    cin>>m>>m;
    for(int i=0;i<(n+1)/2;i++)
        cout<<i+1<<' '<<(n+1)/2*2-i<<endl;
    for(int i=0;i<n/2;i++)
        cout<<(n+1)/2*2+1+i<<' '<<n*2+1-i<<endl;
}