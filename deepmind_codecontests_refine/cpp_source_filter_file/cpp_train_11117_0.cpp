#include<iostream>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int C=0,P=0,w[M],p;
  string S;
  bool a[M];
  
  for(int i=0;i<M;i++){
    a[i]=false; w[i]=0;
  }
  
  for(int i=0;i<N;i++){
    cin>>p>>S;
    if(S=="WA"&&a[p-1]==false){
      w[p-1]++
    }
    if(S=="AC"&&a[p-1]==false){
      C++; P+=w[p-1]; a[p-1]=true;
    }
  }
  cout<<C<<" "<<P;
}
  
  