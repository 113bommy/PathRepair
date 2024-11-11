#include <bits/stdc++.h>
using namespace std;

long long q,rs,n,a;
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i)
	{
		cin>>a;
		
		if(a%2==1)
		{
			rs+=a/2;
			if(q)
			{
			 	q=0;
				rs++;
			}else
			{
				
				q=1;
			}
		}else
		{
			if(a>=2){
			rs+=a/2;
			
			}else
			q=0;
		}
	}
	cout<<rs;
}
