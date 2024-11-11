#include<bits/stdc++.h>
using namespace std;
int n,k,b,a[999999];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=n-k+1;i--)
    {
    	b+=a[i];
    }
    cout<<b;
	return 0;
}
