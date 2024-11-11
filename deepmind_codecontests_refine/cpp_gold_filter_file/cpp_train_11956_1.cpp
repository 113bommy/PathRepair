#include<bits/stdc++.h>
using namespace std;
int main(void){
  
  int i,n,k,xi,s;
  
  cin>>n>>k;
  for(i=0;i<n;i++){
    cin>>xi;
    if(xi < k-xi)s+=2*(xi);
    else s+=2*(k-xi);
  }
  cout<<s;
}