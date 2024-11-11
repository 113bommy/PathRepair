#include<iostream>
using namespace std;
int main(){
long long N,K;
  cin>>N>>K;
  long long asum=0;
  long long bsum=0;
  long long csum=0;
  for (long long j=K;j<=N+1; j++){csum+=j*(N-j+1)
  }
  cout<<csum%1000000007<<endl;
}