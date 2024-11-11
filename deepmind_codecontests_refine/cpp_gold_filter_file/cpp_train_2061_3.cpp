#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;int i;
  for(i=0;i<S.size();i++){
    if((i%2==1&&S.at(i)=='R')||(i%2==0&&S.at(i)=='L'))break;
  }
  if(i==S.size())cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}