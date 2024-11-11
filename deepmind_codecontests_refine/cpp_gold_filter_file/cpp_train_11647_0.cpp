#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int n=S.size();
  if(n==2){
    if(S[0]==S[1])cout<<"1 2"<<endl;
    else cout<<"-1 -1"<<endl;
    return 0;
  }
  for(int i=0;i<n-2;i++){
    if(S[i]==S[i+1]||S[i]==S[i+2]||S[i+1]==S[i+2]){
      cout<<i+1<<" "<<i+3<<endl;
      return 0;
    }
  }
  cout<<"-1 -1"<<endl;
  return 0;
}
