#include<bits/stdc++.h>
using namespce std;
int main(){
  int N;cin>>N;
  string S;cin>>S;
  int x=0,ans=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='I')x++;
    else x--;
    ans=max(x,ans);
  }
  cout<<ans<<endl;
}