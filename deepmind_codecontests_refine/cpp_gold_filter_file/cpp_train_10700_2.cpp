#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin>>N>>K;
  vector<double> sum(N+1);
  sum.at(0)=0;
  for(int i=0;i<N;i++){
    double p;
    cin>>p;
    sum.at(i+1)=(p+1.0)/2.0+sum.at(i);
  }
  
  double ans=0;
  for(int i=0;i<N-K+1;i++){
    ans=max(ans,sum.at(i+K)-sum.at(i));
  }
  
  printf("%lf\n",ans);
}