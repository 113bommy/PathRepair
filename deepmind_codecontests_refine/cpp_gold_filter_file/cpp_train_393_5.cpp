#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int count=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='0') count++;
  }
  cout<<min(count,(int)S.size()-count)*2<<endl;
}