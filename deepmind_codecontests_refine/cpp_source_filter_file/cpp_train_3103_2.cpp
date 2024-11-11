#include <iostream>
#include <vector>
using namespace std;
int main(){
  int N; cin>>N;
  int W;
  int ttl=0;  
  for (int i=0;i<N;++i){
    cin>>W[i];
    ttl+=W[i];
  }
  int mini=ttl;
  int tmp=0;
  for (int i=0;i<N;++i){
    tmp+=W[i];
    mini=min(mini,abs(tmp-(ttl-tmp)));
  }
  cout<<mini<<endl;
}
