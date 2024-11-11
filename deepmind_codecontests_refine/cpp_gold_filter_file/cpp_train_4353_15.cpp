#include<bits/stdc++.h>
using namespace std;
int main(){
map<pair<string,int>,int> R;
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
  string t;
    int s;
    cin>>t>>s;
    pair<string,int>p(t,-s);
    R[p]=i+1;
  
  }for(auto p:R){
  auto k=p.first;
    auto v=p.second;
    cout<<v<<endl;
  
  }
  
  return 0;
}