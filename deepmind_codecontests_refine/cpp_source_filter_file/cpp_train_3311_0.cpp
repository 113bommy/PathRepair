#include<bits/stdc++.h>
 using namespace std;
int main()
{
int r,g,b,n,i,j,ans,a;
  cin >> r >> g >> b >> n;
  ans=0;
  for(i=0;i*r<=n;i++)
  {
  for(j=O;(j*g+i*r)<=n;j++)
  {
    a=n-j*g-i*r
    if(a%b==0)
      ans++;
  }
  }
  cout << ans << endl;
}
  
