#include<bits/stdc++.h>
using namespace std;

#define N 5000 + 10
int f[N][N],n,ans;
char s[N];

int main(){
ios::sync_with_stdio(false);
cin>>n>>s;
for(int i=n-1;i>=0;i--)
for(int j=n-1;j>=0;j--){
if(s[i]==s[j])
f[i][j]=max(f[i][j],f[i+1][j+1]+1);
ans=max(ans,min(f[i][j],j-i));
}
cout<<ans;
}