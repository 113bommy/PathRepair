#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int sum=0;
  long int n,i;
  cin>>n>>k;
  long int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for(i=0;i<n-k;i++)
  {
    sum+=a[i];
  }
  cout<<sum;
  return 0;
}