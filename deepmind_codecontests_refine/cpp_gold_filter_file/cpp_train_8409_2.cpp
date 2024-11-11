#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int i=2; i<=N/2; i++){
    if(N%i==0){
      i=1;
      N++;
      continue;
    }
  }  
  cout<<N<<endl;
}
