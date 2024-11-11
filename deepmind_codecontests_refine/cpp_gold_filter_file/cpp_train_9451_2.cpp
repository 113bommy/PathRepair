#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  string S;cin>>S;
  int ans=0;
  for(int i=0;i<N-1;i++){
    string L=S.substr(i,3);
    if(L=="ABC") ans++;
  }
  cout<<ans<<endl;
}
