#include<bits/stdc++.h>
using namespace std;

signed main(){
string a;cin>>a;
int ans=0;
for(char b:a)if(b=='1')ans++;
cout<<ans<<endl;
}