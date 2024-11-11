
#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N=0;
  int64_t K=0
  cin>>N>>K;
  int64_t total=0;
  for(int64_t i=K; i<N+2; i++){
    total+=N*i-i*(i-1)+1;
  }
  total %=1000000007LL;
  cout<< total;
}
