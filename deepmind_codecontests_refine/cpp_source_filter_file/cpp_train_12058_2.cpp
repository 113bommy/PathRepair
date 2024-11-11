#include<bits/stdc++.h>
using namespace std;
g string s[105];
int n;
int main(){
cin>>n;
for(int i=1;i<=n;i++)cin>>s[i];
for(int i=2;i<=n;i++){
if(s[i][0]!=s[i-1][s[i-1].size()-1])
{ cout<<"No"<<endl;return 0;}
}
for(int i=1;i<n;i++)
for(int j=i+1;j<=n;j++)
{
if(s[i]==s[j]){ cout<<"No"<<endl;return 0;}
}
cout<<"Yes"<<endl;
return 0;