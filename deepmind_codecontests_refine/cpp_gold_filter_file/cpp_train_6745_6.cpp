#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int j=0;
  for(int i=0;i<(S.size()+1)/2;i++){
    if(S[i]!=S[S.size()-1-i])
      j++;
  }
  cout<<j<<endl;
}