#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,S=0,T=0,x;cin>>N;
  for(int i=0;i<N;i++){cin>>x;S+=x;T+=x*x}
  x=(2*S+N)/(2*N);
  cout<<N*x*x-2*S*x+T;
}