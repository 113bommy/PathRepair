 include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,x,ans=0;
	cin>>a>>b>>c>>x;
	for(int i=0;i<=a;i++)
		for(int j=0;j<=b;j++)
			for(int m=0;m<=c;m++)
				if(i*500+j*100+m*50==x)
					ans++;
	cout<<ans;
	return 0;
}