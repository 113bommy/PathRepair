#include <iostream>
using namespace std; typedef long long ll
int main() {
  int n; cin>>n;
  ll a[n],b[n];
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  ll c=0,d=0;
  for(int i=0;i<n;i++) c+=max(0LL,(b[i]-a[i])/2);
  for(int i=0;i<n;i++) d+=max(0LL,a[i]-b[i]);
  if (c-d>=0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}