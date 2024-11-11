#include <bits/stdc++.h>
using namespace std;

int n,a[101];
int ret;
main()
{
 cin>>n;
  for(int i=1;i<=n;++i) cin>>a[i];
  for(int i=1;i<=n-1;++i)
  for(int j=i+1,j<=n;++j)
  {
    ret+=a[i]*a[j];
  }
  cout<<ret
}