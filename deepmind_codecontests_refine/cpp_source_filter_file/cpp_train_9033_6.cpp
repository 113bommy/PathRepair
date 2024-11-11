#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin>>n >>k;
  vector<int> h(n);
  for(int i=0;i<n;i++)cin>>h[i];
  
  sort(h.rbegin(), h.rend());
  
  long long ans=0;
  for(int i=k;i<n;i++)ans+=h[i];
  cout<<max(ans, 0)<<endl;
  return 0;
}