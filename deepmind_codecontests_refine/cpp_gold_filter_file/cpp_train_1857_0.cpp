#include <bits/stdc++.h>
using namespace std;

int main() {

int N,k=0; cin>>N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin>>A.at(i);}
  
  sort(A.begin(),A.end(),greater<int>());
  for(int i=0; i<N;i++){
    if(i%2==0)k+=A.at(i);
    else{k-=A.at(i);}
  }
  cout<<k<<endl;
}
