#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  int l=0,r=n;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    l=max(a,l);
    r=min(b,r);
  }
  if(r>=l)cout<<r-l+1<<endl;
  else cout<<0<<endl;
}
