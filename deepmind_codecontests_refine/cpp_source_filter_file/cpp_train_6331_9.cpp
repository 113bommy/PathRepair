#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  int j=0,k=0;
  for(int i=0;i<N;i++){
    int p;
    cin>>p;
    j=max(j,p);
    k+=p;
  }
  cout<<k-j/2<<endl
}