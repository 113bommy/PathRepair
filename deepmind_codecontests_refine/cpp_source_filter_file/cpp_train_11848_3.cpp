#include <bits/stdc++.h>
using namespace std;
int main(){
  long int N,B,S=0;cin>>N;long int A[N+1];
  for(long int i=0;i<=N;i++)cin>>A[i];
  for(long int i=0;i<N;i++){
    cin>>B;
    if(A[i]<B){
      if(A[i]+A[i+1]<B){S+=A[i]+A[i+1];A[i+1]=0;}
      else{S+=B;A[i+1]+=A[i]-B;{
    }
    else S+=B;
  }
  cout<<S<<endl;
}