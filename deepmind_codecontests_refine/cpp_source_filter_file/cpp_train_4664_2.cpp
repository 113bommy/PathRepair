#include<bits/stdc++.h>
using namespace std;

int main()
{
int a,b; cin>>a>>b;
 
int arr[]={0,300000, 200000,100000};
sum=0;
  if(a>3) a=0;
  if(b>3) b=0;
  sum+=(arr[a]+arr[b]);
  if(a==1 and b==1) sum+=400000;
  cout<<sum;
  

return 0;
}