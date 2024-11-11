#include<bits/stdc++.h>
using namespace std;
main(){
  int a,b;cin>>a>>b;
  string s;
  cin<<s;
  int cnt=0;
  for(int i=0;i<a+b+1;i++){
  if(i==a){
  cnt+=(s[i]=='-');}
  else{
  for(char c='0';c<='9';c++)cnt+=(s[i]==c);}}
  cout<<(cnt==a+b+1?"Yes":"No");
}