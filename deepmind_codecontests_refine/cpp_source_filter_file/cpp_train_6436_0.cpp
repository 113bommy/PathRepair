#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  long *x=new long[n],*y=new long[n],*z=new long[n],*tmp=new long[n];
  for(int i=0;i<n;i++)
  {
    cin >> x[i] >> y[i] >> z[i];
  }
  long ans=0;
  for(int a=-1;a<2;a+=2)
  for(int b=-1;b<2;b+=2)
  for(int c=-1;c<2;c+=2)
  {
    for(int i=0;i<n;i++)
    {
      tmp[i]=a*x[i]+b*y[i]+c*z[i];
    }
    sort(tmp,tmp+n);
    long t=0;
    for(int i=0;i<m;i++)
    {
      t+=tmp[i];
    }
    if(t>ans)ans=t;
  }
  cout >> ans;
  return 0;
}
