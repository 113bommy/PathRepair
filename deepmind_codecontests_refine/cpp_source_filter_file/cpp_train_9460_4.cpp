#include <bits/stdc++.h>
using namespace std;
int main(){
  map<string,vector<int> >A;
  string s;
  int n;
  while(cin>>s>>n){
    A[s].push_back(n);
  }
  map<string,vector<int> >::iterator t=A.begin();
  while(t!=A.end()){
    cout<<t->first<<endl;
    sort(t->second.begin(),t->second.end());
    for(int i=0;i<t->second.size()++){
      if(i)cout<<' '<<t->second[i];
      else cout<<t->second[i];
    }
    cout<<endl;
  }
}