#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i,j,a,b,cnt = 0,maxv = 0;
  cin>>n;
  for(i = 0;i<n;i++)
  {
    cin>>a>>b;
    if(a == b)
      cnt++;
    else
      cnt = 0;
    maxv = max(maxv,cnt);
  }
  if(maxv >= 3)
    cout<<"Yes";
  else
    cout<<"No";
  
}
