#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  vector<int> start(26,-1);
  vector<int> goal(26,-1);
  for(int i=0;i<s.size();i++){
    int a=s[i]-'a';
    int b=t[i]-'a';
    
    if(start[a]!=-1||goal[b]!=-1){
      if(start[a]!=b||goal[b]!=a){
        cout<<"No"<<endl;
        return 0;
      }
    }
    start[a]=b;
    goal[b]=a;
  }
  cout<<"Yes"<<endl;
}