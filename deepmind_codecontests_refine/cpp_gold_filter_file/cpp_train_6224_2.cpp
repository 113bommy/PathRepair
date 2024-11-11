#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll ans,cnt[2200],num,t=1;
int main()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		num=(num+(s[i]-'0')*t)%2019;
		cnt[num]++;
		t=t*10%2019;
	}
	for(int i=1;i<2019;i++)
	{
		if(cnt[i]>1)	ans+=(cnt[i]-1)*cnt[i]/2;		
	}
	ans+=cnt[0]*(cnt[0]+1)/2;
	cout<<ans;
return 0;
}
