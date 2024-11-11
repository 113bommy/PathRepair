#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,sum=0;
  cin>>n;
  int a[n-1];
  for(i=0;i<n-1;i++)
    cin>>a[i];
  sum+=a[0]+a[n-2];
  for(i=1;i<n-1;i++)
  {
    sum+=min(a[i-1],a[i]);
  }
  cout<<sum;
  return 0;
}