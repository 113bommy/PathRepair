#include <iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int maxi=0,mini=1e9;
for(int i=0;i<n;i++)
{
int a;
cin>>a;
maxi=max(maxi,a;
mini=min(mini,a));
}
cout<<maxi-mini<<endl;
return 0;
}