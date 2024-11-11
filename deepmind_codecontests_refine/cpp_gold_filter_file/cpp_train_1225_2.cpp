#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,i,sum=0;
  cin>>n>>k;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
  sort(a,a+n);
  for(i=0;i<k;i++)
  sum+=a[i];
  cout<<sum;
  return 0;
}