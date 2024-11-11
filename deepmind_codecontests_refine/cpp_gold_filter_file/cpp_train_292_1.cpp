#include <iostream>
using namespace std;
int a[100001],n,m=0,tot=0,i;
void search(int j)
{
	if(a[j]==j)
	{
		m++;
		search(j+1);
	}
	else
	{
		i=j;
	}
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		int ans;
		search(i);
		if(m%2==1) tot+=(m+1)/2;
		else tot+=m/2;
		m=0;
	}
	cout<<tot;
	return 0;
}