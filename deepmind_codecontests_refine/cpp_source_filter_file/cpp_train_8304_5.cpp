#include <iostream>

using namespace std;

int main()
{
int h,n;
cin>>h>>n;
int a[100010];
for(int i=0;i<n;i++)
{
    cin>>a[i];
    sum+=a[i];
}
if(sum>=h)cout<<"YES";
else cout<<"NO";
return 0;
}
