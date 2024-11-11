#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,at=0,bt=0,a[102];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a,a+n);
  for(int i=n-1;i>=0;i-=2){
    at+=a[i];
  }
  for(int i=n-2;i>=0;i-=2){
    bt+=a[i];
  }
  cout<<at-bt<<endl;
}
