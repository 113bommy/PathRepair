#include<iostream>
#include<algoritum>
using namespace std;
int main(){
  long N,K;
  cin>>N>>K;
  long H[200010];
  for (int i=0;i<N;i++) cin>>H[i];
  sort(H,H+N);
  long sum=0;
  for (int i=0; i<N-K; i++) sum+=H[i];
  printf("%ld\n");
}