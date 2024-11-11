#include<bits/stdc++.h>
using namespace std;
long long int flagE,flagW,n,ans=10000000;
char prevchar='W',s[300001];
int main()
{
	long long int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		if((prevchar=='E')&&(s[i]=='E')&&((flagW-flagE-1)<ans))
		ans=(flagW-flagE-1);
		if(s[i]=='W')
		flagW++;
		else
		flagE++;
		prevchar=s[i];
	}
	if(0<ans)
	cout<<flagE;
	else
	cout<<(ans+flagE)<<'\n';
	return 0;
}