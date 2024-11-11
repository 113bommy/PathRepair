#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,M;cin>>N>>M;
  vector<long>A(N,0);
  for(long i=0;i<M;i++){
    long a,b;cin>>a>>b;A[a-1]++;B[b-1]++;
  }
  bool a=1;
  for(long i=0;i<N;i++)a*=(A[i]%2==0);
  cout<<(a?"YES":"NO");
}