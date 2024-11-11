#include<iostream>
using namespace std;
int main(void){
  string s[110],t[110];
  int n,m;cin>>n;
  for(int i=0;i<n;i++)cin>>s[i];
  cin>>m;
  for(int i=0;i<m;i++)cin>>t[i];
  int ans=0;
  for(int i=0;i<n;i++){
    int sc=0;
    for(int j=0;j<n;j++)if(s[i]==s[j])sc++;
    for(int j=0;j<m;j++)if(s[i]==t[j])sc--;
    ans=max(ans,sc);
  }
  cout<<ans<<endl;
  return 0;
}