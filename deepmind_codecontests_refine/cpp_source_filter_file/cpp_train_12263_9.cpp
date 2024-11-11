#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin>>N;
  for(long long i=0;i<N;i++){
    if(i*10800/10000==N){
      cout<<i<< endl;
      return 0;
    }
  }
  cout<<":("<< endl;
  
  
}