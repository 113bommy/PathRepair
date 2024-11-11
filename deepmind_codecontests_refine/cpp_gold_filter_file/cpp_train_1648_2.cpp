#include<bits/stdc++.h>
using namespace std;

int main(){
  string S,T,Text;
  
  cin>>S>>T;
  for(int i=0;i<S.size();i++){
    if(T==S.substr(i)+S.substr(0,i)){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}