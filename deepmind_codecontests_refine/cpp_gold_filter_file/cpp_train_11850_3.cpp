#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M; cin>>N>>M;
  int k=M/N;
  while(k){
    if(M%k)
      k--;
    else
      break;
  }
  cout<<k;
}