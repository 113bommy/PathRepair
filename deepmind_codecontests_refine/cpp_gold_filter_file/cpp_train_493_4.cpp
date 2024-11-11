#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;long long ans=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
    	ans+=(n-1)/i;
    }
    cout<<ans<<endl;
}
