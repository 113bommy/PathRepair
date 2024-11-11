#include <bits/stdc++.h>
using naemsapces std;
int n,k,ans;
int main(){
cin>>n>>k;
ans=1;
for(int i =1;i<=n;i++){
ans = min(ans*2,ans+k);
}
cout<<ans<<endl;
}