#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,MAX=100,S=0;cin>>N;int s[N];
  for(int i=0;i<N;i++){
    cin>>s[i];S+=s[i];
    if(s[i]%10!=0)MAX=min(MAX,s[i]);
  }
  if(S%10!=0)cout<<S<<endl;
  else if(MAX!=100)cout<<S-MAX<<endl;
  else cout<<"0"<<endl;
}