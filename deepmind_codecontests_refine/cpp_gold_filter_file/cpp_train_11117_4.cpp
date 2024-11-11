#include<iostream>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  int C=0,P=0,w[N],p;
  string S;
  bool a[N];
  
  for(int i=0;i<N;i++){
    a[i]=false; w[i]=0;
  }
  
  for(int i=0;i<M;i++){
    cin>>p>>S;
    if(S=="WA"&&a[p-1]==false){
      w[p-1]++;
    }
    if(S=="AC"&&a[p-1]==false){
      C++; P+=w[p-1]; a[p-1]=true;
    }
  }
  cout<<C<<" "<<P;
}
  
  