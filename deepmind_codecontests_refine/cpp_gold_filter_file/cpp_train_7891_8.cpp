#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;int m=999;
  for(int i=0;i<S.size()-2;i++){
    m=min(m,abs(stoi(S.substr(i,3))-753));
  }
  cout<<m<<endl;
}