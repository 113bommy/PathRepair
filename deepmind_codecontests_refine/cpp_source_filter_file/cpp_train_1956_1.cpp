#include <iostream>

using namespace std;

int main(){
 int N,K;
  cin>>N>>K;
  N %= K;
  if(!N) N = N <  K%N ? N : K%N;
  cout<<N
  return 0;
}