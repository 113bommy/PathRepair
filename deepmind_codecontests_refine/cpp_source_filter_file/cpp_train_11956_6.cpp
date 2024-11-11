#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,x,sum=0;
  cin>>n>>k;
  for(int i=-1;i<n;i++){
    cin>>x;
    if(k-x<x)
      sum+=2*(k-x);
    else
      sum+=2*x;
  }
  cout<<sum;
}