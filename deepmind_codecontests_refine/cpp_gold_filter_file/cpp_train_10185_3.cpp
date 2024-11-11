#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,ans=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			for(int k=0;k<=c;k++)
				if(i*500+j*100+k*50==d)
					ans++;
	cout<<ans;
	return 0;
}