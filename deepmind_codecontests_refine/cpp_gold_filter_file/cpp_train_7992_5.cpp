#include<iostream>
using namespace std;

int main(){
  int N,M,ans;
  cin>>N>>M;
  ans=N*(N-1)/2+M*(M-1)/2;
  cout<<ans;
}