#include<bits/stdc++.h>
using namespace std;
int main()
{	
	long long t=0,c=0;
	int n,i,k;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>k;
		if(k==0)
		{
			t+=c/2;
			c=0;
		}
		c+=k;
	}
	t+=c/2;
	cout<<t<<endl;
 	return 0;
} 