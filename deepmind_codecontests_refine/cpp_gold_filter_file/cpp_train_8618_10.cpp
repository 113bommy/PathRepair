#include<iostream>

using namespace std;

int main(){
  int N,K,ans=0;
  cin>>N>>K;
  for(int i=0;i<N;++i){
    int x;
    cin>>x;
    if(x>=K)ans++;
  }
  
  cout<<ans<<endl;
}