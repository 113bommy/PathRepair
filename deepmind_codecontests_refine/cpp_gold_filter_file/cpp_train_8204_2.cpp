#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;
	for(int i=1;i<n-1;i++)
	{
		map<char,int> l;
		int anso=0;
		for(int j=0;j<i;j++) l[s[j]]++;
		for(int j=i;j<n;j++)
		{
			if(l[s[j]]) anso++,l[s[j]]=0;
		}
		ans=(anso>ans?anso:ans);
		l.clear();
	}
	cout<<ans<<'\n';
	return 0;
}