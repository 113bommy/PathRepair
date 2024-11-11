#include<bits/stdc++.h>
using namespace std;
main(){
  long n,k=0;
  cin>>n;
  vector<int> a(n),b(n);
  for(auto &i:a)cin>>i,k-=i;
  for(auto &i:b)cin>>i,k+=i;
  for(int i=;i<n;++i)if(a[i]<b[i])k-=(b[i]-a[i]+1)/2;
  cout<<(s<0?"No":"Yes");
}