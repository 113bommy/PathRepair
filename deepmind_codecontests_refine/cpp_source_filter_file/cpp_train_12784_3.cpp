#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,s;
	cin>>a>>s;
	int d,f=0;
	for(int i=1;i<=a;i++)
	{
		cin>>d;
		f+=d;
		if(f>s){
			cout<<i;
			return 0;
		}
	}
	cout<<i+1;
	return 0;
}
