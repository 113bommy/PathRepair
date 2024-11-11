#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;++i)
    cin>>a[i];
  int len=1,now=1;
 for(int i=0;i<n-1;++i)
 {
   if(a[i]>=a[i+1])
     now++;
   len=max(len,now);
   else now=1;
 }
  cout<<len;
  return 0;
}
   
   