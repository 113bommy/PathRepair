#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k,i;
  cin>>n>>k;
  int L[n]
  for(i=0;i<n;i++){
  	cin>>L[n];
  }
  sort(L,L+n,greater<int>());
  int sum=0;
  for(i=0;i<k;i++){
    sum+=L[i];
  }
  cout<<sum;
}