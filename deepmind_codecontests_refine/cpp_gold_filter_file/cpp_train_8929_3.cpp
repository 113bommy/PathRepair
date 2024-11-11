#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  map<string,int>r;
  int mx=0;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    r[s]++;
    mx=max(r[s],mx);
  }
  for(auto p:r){
    if(p.second==mx){
      cout<<p.first<<endl;
    }
  }
}
  
