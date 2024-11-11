#include<bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize(3)
using namespace std;
int r,l,ans; string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	r=s.length()-1;
	while(l<=r)
	{
		if(s[l]==s[r]) l++,r--;
		else
			if(s[l]=='x'||s[r]=='x')
			{
				ans++;
				s[l]=='x'?l++:r--;
			} 
			else
			{
				cout<<-1<<endl;
				return 0;
			}
	}
	cout<<ans<<endl;
}

