#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,i;cin>>n;
  vector<long long> a[n];
  for(i=0; i<n; ++i) cin>>a[i];
  sort(a.rbegin(),a.rend());
  if(a[a.size()-1]==0){cout<<0<<endl;return 0;}
  long long b=1,c=1e18;
  for(i=0; i<n; ++i){
    b*=a[i];c/=a[i];
    if(c==0){cout<<-1<<endl;return 0;}
  }
  cout<<b<<endl;
  return 0;
}
