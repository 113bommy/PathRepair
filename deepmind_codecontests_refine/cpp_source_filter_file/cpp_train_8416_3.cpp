#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;
  cin>>n>>x;
  vector<int> a(n);
  for(auto &i:a)
     cin>>i;
  long long int ans=0;
  for(int i=0;i<n-1;i++)
    if(a[i]+a[i+1]>x)
      {
        long long sub = a[i+1]+a[i]-x;
        ans += sub;
        a[i+1]=max(a[i+1]-sub,0);
      }
  if(a[n-1]>x)
    ans += a[n-1]-x;
  cout<<ans<<"\n";
  return 0;
}
