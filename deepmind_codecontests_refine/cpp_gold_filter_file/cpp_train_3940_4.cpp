#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K,sum=1;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    sum=min(sum*2,sum+K);
  }
  cout<<sum<<endl;
}