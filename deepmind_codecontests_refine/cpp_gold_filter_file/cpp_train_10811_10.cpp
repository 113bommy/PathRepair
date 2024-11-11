#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,x=0,maxv=0;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++){
    x+=(s[i]=='I'?1:-1);
    maxv=max(maxv,x);
  }
  cout<<maxv<<endl;
}
  
