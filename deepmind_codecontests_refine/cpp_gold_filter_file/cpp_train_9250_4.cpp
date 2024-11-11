#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int N,K,X,Y;cin>>N>>K>>X>>Y;
  cout<<X*min(N,K)+Y*max(N-K,0)<<endl;
  return 0;
}