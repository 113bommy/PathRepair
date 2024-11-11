#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=1e9+7;
signed main(){
    int m;
    cin>>m>>m;
    for(int i=0;i<(m+1)/2;i++)
        cout<<i+1<<' '<<(m+1)/2*2-i<<endl;
    for(int i=0;i<m/2;i++)
        cout<<(m+1)/2*2+1+i<<' '<<m*2+1-i<<endl;
}