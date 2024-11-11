#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,a,b;
    cin>>n>>a>>b;
    cout<<max(0,(n-1)*b+a-(n-1)*a-b+1)<<endl;
}