#include<bits/stdc++.h>
using namespace std;
string a;
int ans;
int main()
{
	cin>>a;
	for(int s=1;s<a;s++)
	{
		if(a[s]!=a[s-1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}