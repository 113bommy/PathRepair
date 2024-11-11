#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);for(int i=0;i<N;i++)cin>>A[i];
  vector<int>B(N,0);
  for(int i=N-1;i>=0;i--){
    int t=0;
    for(int j=2;j*(i+1)<=N;j++)t+=B[i*j-1];
    B[i]=(t+A[i])%2;
  }
  int M=0;
  for(int i=0;i<N;i++)M+=B[i];
  cout<<M<<endl;
  for(int i=0;i<N;i++)if(B[i])cout<<i+1<" ";;
}

