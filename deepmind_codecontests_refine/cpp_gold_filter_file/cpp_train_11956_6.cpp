#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,a=0;cin>>n>>k;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    a+=min(abs(x),abs(x-k));
  }
  cout<<a*2<<endl;
}
