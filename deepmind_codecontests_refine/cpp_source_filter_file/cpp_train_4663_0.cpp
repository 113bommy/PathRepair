#include <iostream>
#include <stdio.h>
using namespace std;
main(){
  long long N,NN;
  scanf("%lld",&N);
  if(N==2){printf("1");return;}
  long long ans=2;
  for(long long K=2;K*K<=N;K++){
    if((N-1)%K){
      NN=N;
      while(!(NN%K)){
        NN=NN/K;
      }
      if(NN%K==1)ans++;
    }else{
      if(K*K==N-1)ans++;
      else ans+=2;
    }
  }
  printf("%d",ans);
}