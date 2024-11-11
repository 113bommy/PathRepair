#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X;
  cin>>N>>X;
  int j=1000;
  for(int i=0;i<N;i++){
    int k;
    cin>>k;
    j=min(j,k);
    X-=k
  }
  cout<<N+X/j<<endl;
}