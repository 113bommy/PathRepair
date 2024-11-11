#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,x;
  cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if(x!=i)
      cnt++;
  }
  (cnt<=2)?cout<<"YES":cout<<"NO";
  return 0;
}
