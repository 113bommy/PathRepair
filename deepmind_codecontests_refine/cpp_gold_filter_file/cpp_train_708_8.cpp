#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,n;
  string h;
  cin>>a>>b>>h;
  
  for(int i=0;i<h.size();i++){
    if(h[i]=='-'){
      ++n;
    }
  }
  
  if(n==1&&h[a]=='-'){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
