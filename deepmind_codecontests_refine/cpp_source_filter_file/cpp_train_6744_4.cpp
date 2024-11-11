#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,x,a[200010]
int main()
{
cin>>n;
for(int i=2;i<=n;i++)
{
	cin>>x;
	a[x]++;
}
for(int i=1;i<=n;i++)
cout<<a[i]<<endl;
return 0;

}