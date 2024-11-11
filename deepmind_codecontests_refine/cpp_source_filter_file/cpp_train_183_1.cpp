#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  int a[25],b[25],c[25];
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i)cin>>bi];
  for(int i=0;i<n;++i)cin>>ci];
  int res=0;
  for(int i=0;i<n;++i){
    res+=b[a[i]-1];
    if(a[i]+1==a[i+1])res+=c[a[i]-1];
  }
  out<<res;
}