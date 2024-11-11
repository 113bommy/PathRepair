#include  <bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int h[n],ma[n];
   for(int i=1;i<=n;i++)
   {
      cin>>h[i];
	  ma[i]=0;
   }
   
   for(int i=0;i<m;i++)
   {
      int a,b;
	  cin>>a>>b; 
	  ma[a]=max(ma[a],h[b]);
	  ma[b]=max(ma[b],h[a]);
   }
   
   int ans=0;
   for(int i=1;i<=n;i++)
   {
      ans += h[i]>ma[i];
   }
   
   cout<<ans<<endl;
}