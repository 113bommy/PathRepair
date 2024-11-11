#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n+1],b[n];
	for(int i=0;i<n+1;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ll c=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]>a[i])
		{
			c+=a[i];
			b[i]-=a[i];
			if(b[i]>a[i+1])
			{
				c+=a[i+1];
				a[i+1]=0;
			}
			else
			{
				c+=b[i];
				a[i+1]-=b[i];
			}
		}
		else 
		{
			c+=b[i];
		}
	}
	cout<<c<<endl;
	
}