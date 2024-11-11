#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,;
  int d[100005];

  cin>>n;
  for(int i=0;i<n;i++) cin>>d[i];

  sort(d,d+n);

  cout<<d[n/2]-d[n/2-1]<<endl;

  return 0;
}
