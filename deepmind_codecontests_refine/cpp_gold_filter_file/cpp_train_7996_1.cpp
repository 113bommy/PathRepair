#include <bits/stdc++.h>
using namespace std;


int main() {
  string S;
  long N,a=0;
  cin>>S>>N;
  for(long long i=0;i<N;i++){
    if(S.at(i)!='1'){
      cout<<S.at(i);
      a=1;
      break;
    }
  }
  if(a==0){
    cout<<'1';
  }
  
}
