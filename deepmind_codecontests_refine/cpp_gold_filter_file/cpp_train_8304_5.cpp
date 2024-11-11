#include <iostream>

using namespace std;

int main()
{
int h,n,sum=0;
cin>>h>>n;
int a[100010];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    sum+=a[i];
}
if(sum>=h)cout<<"Yes";
else cout<<"No";
return 0;
}
