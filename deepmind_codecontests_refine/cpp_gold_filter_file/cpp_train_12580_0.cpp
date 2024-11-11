#include<bits/stdc++.h>
using namespace std;
long long n,k,a[55],ans;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=n-1;i>=n-k;i--)
    ans+=a[i];
	cout<<ans<<endl;
	return 0;
}