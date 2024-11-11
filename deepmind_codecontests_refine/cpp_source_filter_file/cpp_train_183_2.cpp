#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,sum=0;
  cin>>n;
  int a[n],b[n],c[n-1];
  for(int i=0;i<n;++i)
   cin>a[i];
   
  for(int i=0;i<n;++i)
  {cin>>b[i];
   sum+=b[i];
  }
  for(int i=0;i<n-1;++i)
    cin>>c[i];
  for(int i=0;i<n-1;++i)
  {if(a[i+1]-a[i]==1)
      sum+=c[i];
  }
  cout<<sum;
  return 0;
}