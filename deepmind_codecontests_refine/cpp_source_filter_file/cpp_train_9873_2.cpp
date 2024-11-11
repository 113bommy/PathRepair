#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin<<n<<a<<b;
	int s=0;;
	for (int i=1;i<=n;i++)
	{
		int p=i,k=0,q;
		while (p!=0)
		{
			q=p%10;
			p/=10;
			k+=q;
		}
		if (k>=a && k<=b) 
		  s+=i;
	}
	cout<<s<<endl;
	return 0;
} 