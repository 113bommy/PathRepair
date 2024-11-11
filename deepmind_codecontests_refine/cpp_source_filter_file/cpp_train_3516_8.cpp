#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int a[n]; 
  int xor=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    xor^=a[i];
  }
  for(int i=0;i<n;i++){ cout<<xor^a[i]<<endl;}
  return 0;
}
  