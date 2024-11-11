#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  for(int i=0;i<S.size()-1)
    if(S.at(i)=='A' && S.at(i+1)=='C'){
      cout<<"Yes"<<endl;
      return 0;
    }
  cout<<"No"<<endl;
}