#include<bits/stdc++.h>
using namespace std;
int n,k,c;//n个数字 k工作天数 c休息天数 
char s[200001];
int start[200001],end[200001],day;
int main()
{
	cin>>n>>k>>c;
	cin>>s;
	day=0;
	for(int i=0;i<n;i++)
	{
		if(day==k)break;
		if(s[i]=='x')continue;
		start[++day]=i;
		i+=c;
	}
	day=0;
	for(int i=n-1;i>=0;i--)
	{
		if(day==k)break;
		if(s[i]=='x')continue;
		end[++day]=i;
		i-=c;
	}
	for(int i=1;i<=k;i++)
		if(start[i]==end[k-i+1])cout<<end[k-i+1]+1<<endl;
	return 0;
}