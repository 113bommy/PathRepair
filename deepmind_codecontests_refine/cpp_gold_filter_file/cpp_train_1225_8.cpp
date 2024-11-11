#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
  int k,n;
  cin>>n>>k;
  int p[n],ans=0;
  for(int i=0;i<n;i++)cin>>p[i];
  sort(p,p+n);
  for(int i=0;i<k;i++)
  {
    ans+=p[i];
  }
  cout<<ans<<endl;
}