#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int h[n];
  int d[n-1];
  for(int i=1;i<=n;i++)
    cin>>h[i];
  d[0]=0;d[1]=abs(h[1]-h[0]);
  for(int i=2;i<n;i++)
    d[i]=min( d[i-1]+abs(h[i]-h[i-1]) , d[i-2]+abs(h[i]-h[i-2]) )
  cout<<d[n-1];
}
 