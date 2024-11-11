#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
cin>>N;
map<int,int> mp;
for(int i=0;i<N;i++){
int a;
cin>>a;
mp[a]++;
}
int ans = 0;
for(auto it:mp){
if(it.sc%2==1) ans++;
}
cout<<ans<<endl;
}