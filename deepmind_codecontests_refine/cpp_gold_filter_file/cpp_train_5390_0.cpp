#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
  int n;
  cin>>n;
  
  string g;
  cin>>g;
  
  int r=0,w=0;
  
  for(auto x:g)
    r+=(x=='R');
  
  for(int i=0;i<r;i++)
    w+=(g[i]=='W');
  
  cout<<w<<endl;
  
}