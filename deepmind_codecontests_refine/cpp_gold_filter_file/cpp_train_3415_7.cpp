#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,L,i;
  cin>>n>>L;
  if(L>=0){
    cout<<n*L+n*(n-1)/2-L;
    return 0;
  }
  if(L+n-1>=0){
    cout<<n*L+n*(n-1)/2;
    return 0;
  }
  cout<<n*L+n*(n-1)/2-(L+n-1);
}