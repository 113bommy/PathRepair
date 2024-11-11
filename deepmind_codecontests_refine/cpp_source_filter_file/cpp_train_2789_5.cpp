#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i,a,wa=0,nijo=0;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a;
    wa+=a;
    nijo+=a**2
  }
  cout<<wa**2-nijo;
}