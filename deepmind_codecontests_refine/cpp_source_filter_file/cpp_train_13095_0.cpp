#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>s;
  for(int i=0;i<S.size()-1;i++){
    if(S.at(i)==S.at(i+1)){
      N--;
    }
  }
  cout<<N<<endl;
}