#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n]; 
  int xo=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    xo^=a[i];
  }
  for(int i=0;i<n;i++){ cout<<xo^a[i]<<endl;}
  return 0;
}