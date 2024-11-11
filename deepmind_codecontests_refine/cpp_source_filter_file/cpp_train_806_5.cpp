#include <bits/stdc++.h>
using namespace std;
long long N,a,b,ans=0,i;
dz(int i,int ns,int ne)
{
	for(i=ns;i<ne;i++)
	{
		cin>>b;
		if(a>b) 
		ans+=a-b;
		else 
    	a=b;
	}
}
int main() 
{	
	cin>>N>>a;
	dz(i,1,N);
	cout<<ans<<endl;
	return 0;
}