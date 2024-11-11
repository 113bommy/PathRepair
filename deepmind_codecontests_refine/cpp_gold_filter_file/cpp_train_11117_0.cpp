#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,p,a=0,w=0;string J;cin>>N>>M;
  vector<bool>x(N,false);
  vector<int>WA(N,0);
  for(int i=0;i<M;i++){
    cin>>p>>J;
    if(J=="AC"){
      if(!x.at(p-1)){a++;x.at(p-1)=true;w+=WA.at(p-1);}
    }
    else if(!x.at(p-1))WA.at(p-1)++;
  }
  cout<<a<<" "<<w<<endl;
}