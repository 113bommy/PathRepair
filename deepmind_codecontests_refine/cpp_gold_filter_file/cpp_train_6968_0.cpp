#include<bits/stdc++.h>
using namespace std;
string s[100];
int n,j,i;
int dfs(int p){

  int res=0,o=s[j].size();

  if(isdigit(s[j][p]))return s[j][p]-'0';

  if(s[j][p]=='+')
    while(s[j+1].size()>o)j++,res+=dfs(p+1);

  else{
    res=1;
    while(s[j+1].size()>o)j++,res*=dfs(p+1);
  }

  return res;
}
int main(){
  while(cin>>n,n){

    for(j=i=0;i<100;i++)s[i]="";
    for(i=0;i<n;i++)cin>>s[i];

    cout<<dfs(0)<<endl;
  }
}