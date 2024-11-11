#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int k=s.size(),a=0,b=0;
  for(int i=0;i<k;i++){
    if(s.at(i)=='o')a++;
    else b++;
  }
  if(a-b+15-k>0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}