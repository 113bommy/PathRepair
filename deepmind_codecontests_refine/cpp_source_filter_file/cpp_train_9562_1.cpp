#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,t;
  cin>>n>>t;
  vector<long long>a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  long long ans=t;
  for(int i=0;i<n-1;i++){
    if(a[i+1]-a[i]>k) ans+=k;
    else ans+=a[i+1]-a[i];
  }
  cout<<ans<<endl;
}
