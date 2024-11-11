#include<iotream>
using namespace std;
int main()
{
int n,x=0;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
  for(int j=1;j<n-1;j++){
    if(a[j]==a[j-1])
  {x++;j++;}}
cout<<x;
}