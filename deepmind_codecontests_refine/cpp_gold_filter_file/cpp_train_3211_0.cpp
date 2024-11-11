#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n,l,b,ans;
  cin>>n>>l>>b;
  long long a[n];
  for(int i=0;i<n;i++){
    long long k;
    cin>>k;
    a[i]=k;
  }
  if(n==1)ans=abs(a[0]-b);
  else{
    ans=max(abs(a[n-1]-a[n-2]),abs(a[n-1]-b));
  }
  cout<<ans<<endl;
}
