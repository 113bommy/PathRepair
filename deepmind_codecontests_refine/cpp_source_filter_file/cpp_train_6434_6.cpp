#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,;cin>>n>>m;
  int l=0,r=n;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    l=max(a,l);
    m=min(b,m);
  }
  if(m>=n)cout<<m-n+1<<endl;
  else cout<<0<<endl;
}
