#include<bits/stdc++.h>
using namespace std;

int main(){
 int t;
  cin>>t;
  set<string> s;
  while(t--){
    string g;
    cin>>g;
    s.insert(g);
  }
  
  cout<<s.size()<<"\n";
  
  return 0;
}
